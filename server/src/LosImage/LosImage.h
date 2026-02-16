
#pragma once
#include <X11/X.h>
#include <X11/Xlib.h>
#include <cstdint>

#include "cstdio"


class LosImage
{
private:
    XImage * LOS_image;
    uint32_t LOS_width;
    uint32_t LOS_height;
    uint32_t LOS_x;
    uint32_t LOS_y;

public:

    uint32_t width() const;
    uint32_t height() const;
    uint32_t x() const;
    uint32_t y() const;
    XImage * image() const;

    bool CaptureArea(
        Display* display,
        Window window,
        int x,
        int y,
        int width,
        int height
    );

    bool CaptureWindow(
        Display* display,
        Window window
    );

    void release();

    LosImage();
    ~LosImage();

};