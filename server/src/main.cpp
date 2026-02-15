
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>
#include <iostream>
#include <vector>
#include <jpeglib.h>

int main()
{
    std::cout << " hello world " << std::endl;

    Display* display = XOpenDisplay(nullptr);

    if(!display)
    {
        
    }


    return 0;
}