#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>

#undef Status
#undef Success

#include <chrono>
#include <cstdint>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <jpeglib.h>

#include "LosImage/LosImage.h"
#include "LosJpeg/LosJpeg.h"
#include "LosTcpServer/LosTcpServer.h"
#include "LosErrorSet/LosErrorSet.h"
#include "logger.h"
#include "protocal.pb.h" 

int main() {
    XSetErrorHandler(LosXErrorHandler);
    LOGI("Server begin ...");

    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        LOGE("Connect X server failed");
        return -1;
    }

    Window root = XDefaultRootWindow(display);
    
    int screen_width = DisplayWidth(display, DefaultScreen(display));
    int screen_height = DisplayHeight(display, DefaultScreen(display));

    LosImage image;
    LosJpeg jpeg;
    LosTcpServer server;

    
    XWindowAttributes attr;
    XGetWindowAttributes(display, root, &attr);
    LOGI("Root Window ID: " + std::to_string(root));
    LOGI("Root Window Depth: " + std::to_string(attr.depth));
    LOGI( (attr.c_class == InputOnly ? "InputOnly" : "InputOutput"));

    if (!server.start_l(9000)) {
        LOGE("Failed to start tcp server on port 9000");
        XCloseDisplay(display);
        return -1;
    }

    while (true) {
        if (!server.accept_l()) {
            LOGE("Accept failed, retrying...");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        }

        LOGI("Client connected, starting stream...");

        for (int i = 0; i < 10; i++) {
            if (!image.CaptureWindow(display, root)) {
                LOGE("Capture failed ...");
                continue;
            }

            int quality = 60;
            std::vector<unsigned char> data = jpeg.compressXimage(image, quality);

            if (data.empty()) {
                LOGE("Compress failed ...");
                continue;
            }

            los_protocal::LosMessage msg;
            msg.set_type(los_protocal::Msgtype::IMAGE);
            msg.set_sequence(i);

            auto* frame = msg.mutable_image_frame();
            frame->set_data(data.data(), data.size());
            frame->set_width(screen_width);
            frame->set_height(screen_height);
            frame->set_quality(quality);

            if (!server.send_l(msg)) {
                LOGE("Send failed, client might have disconnected");
                break; 
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(33));

            if (i % 30 == 0) {
                LOGI("Has sent " + std::to_string(i) + " frames");
            }
        }
        
        LOGI("Stream ended, waiting for next client...");
    }

    LOGI("Shut down server...");
    server.stop_l();
    XCloseDisplay(display);
    return 0;
}
