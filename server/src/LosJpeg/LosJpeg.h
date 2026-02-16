
#pragma  once
#include <cstdio>
#include <vector>
#include <iostream>
#include <X11/Xlib.h>

extern "C" {
    #include <jpeglib.h>
}

#include "LosImage/LosImage.h"
#include "LosBuf/LosBuf.h"

class LosJpeg{

public:
    LosJpeg();
    ~LosJpeg();
    std::vector<unsigned char> compressXimage(const LosImage& image,int quality);

private:
    struct jpeg_compress_struct LOS_compress;
    struct jpeg_error_mgr LOS_errorMgr;
};