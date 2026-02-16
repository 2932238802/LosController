
#include "LosImage.h"


/**
26_2_15
- 默认构造
*/
LosImage::LosImage():
    LOS_height(0),
    LOS_width(0),
    LOS_x(0),
    LOS_y(0),
    LOS_image(nullptr)
{
}


/**
26_2_15
- 销毁
*/
LosImage::~LosImage() {
    release();
}


/**
26_2_15
- 获取 图片裸指针
*/
XImage * LosImage::image() const{
    return LOS_image;
}



/**
26_2_15
- 获取 区域
*/
bool LosImage::CaptureArea(
    Display* display,
    Window window,
    int x,
    int y,
    int width,
    int height
){
    release();

    printf("DEBUG: Requesting XGetImage from Window ID: 0x%lx, x=%d, y=%d, w=%d, h=%d\n", 
            window, x, y, width, height);

    LOS_image = XGetImage(
        display, 
        window, 
        x, 
        y, 
        width, 
        height, 
        AllPlanes, 
        ZPixmap);

    if(nullptr == LOS_image) return false;

    LOS_x = x;
    LOS_y = y;
    LOS_width = width;
    LOS_height = height;
    return true;
}



/**
26_2_15
- 获取 屏幕

26_2_15
- 如果拓展屏幕的逻辑
- 用 DefaultScreen
*/
bool LosImage::CaptureWindow(
    Display* display,
    Window window
){
    // XWindowAttributes gwa;
    // if(!XGetWindowAttributes(display, window,&gwa))
    // {
    //     return false;
    // }

    int screen_num = DefaultScreen(display);

    int width = DisplayWidth(display, screen_num);
    int height = DisplayHeight(display, screen_num);

  

    return CaptureArea(
        display, 
        window, 
        0,0, width, height);
}



/**
- 释放内存
*/
void LosImage::release(){
    if(LOS_image)
    {
        XDestroyImage(LOS_image);
        LOS_image = nullptr;
    }
}



/**
26_2_15
- 宽度
*/
uint32_t LosImage::width()const{
    return LOS_width;
}

/**
26_2_15
- 高度
*/
uint32_t LosImage::height()const{
    return LOS_height;
}


/**
26_2_15
- 初始 x
*/
uint32_t LosImage::x()const{
    return LOS_x;
}


/**
26_2_15
- 初始 y
*/
uint32_t LosImage::y()const{
    return LOS_y;
}
