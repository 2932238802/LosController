
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <ratio>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <jpeglib.h>
#include "LosImage/LosImage.h"
#include "LosJpeg/LosJpeg.h"
#include "LosTcpServer/LosTcpServer.h"
#include "LosErrorSet/LosErrorSet.h"
#include "logger.h"


int main()
{
    XSetErrorHandler(LosXErrorHandler);
    
    LOGI("begin ...");

    Display* display = XOpenDisplay(nullptr);

    if(!display)
    {
        LOGE("connect X server failed"); return -1;
    }

    Window root = XDefaultRootWindow(display);

    LosImage image;
    LosJpeg jpeg;
    LosTcpServer server;

    uint32_t port = 9000;

    if(!server.start_l(port))
    {
        LOGE("failed to start tcp server ...");
        XCloseDisplay(display);
        return -1;
    }

    if(!server.accept_l())
    {
        LOGE("accept wrong...");
        XCloseDisplay(display);
        return -1;
    }

    for(int i =0 ; i < 1000; i++)
    {
        if(!image.CaptureWindow(display, root))
        {
            LOGE("capture failed ...");
            continue;
        }

        std::vector<unsigned char> data =
            jpeg.compressXimage(image,60);

        if(data.empty())
        {
            LOGE("compress failed ...");
            continue;
        }

        if(!server.send_l(data))
        {
            LOGE("send failed");
            break;
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(33)
        );

        if(i % 10 == 0)
        {
            std::string msg{"has sent "};
            msg += std::to_string(i);
            LOGI(msg);
        }
    }

    LOGI("shut down server...");
    server.stop_l();
    XCloseDisplay(display);
    return 0;
}