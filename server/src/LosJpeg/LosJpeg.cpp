
#include"LosJpeg.h"
#include "LosBuf/LosBuf.h"


LosJpeg::LosJpeg()
{
    LOS_compress.err = jpeg_std_error(&LOS_errorMgr);
    jpeg_create_compress(&LOS_compress);
}


LosJpeg::~LosJpeg(){
    jpeg_destroy_compress(&LOS_compress);
}


/**
26_2_15
- 压缩 图片
*/
std::vector<unsigned char> LosJpeg::compressXimage(const LosImage& image,int quality){

    if(
        nullptr == image.image() ||
        nullptr == image.image()->data
    ) return {};

    unsigned char* outbuffer = nullptr; LosBuf buf(&outbuffer);
    unsigned long outsize = 0;

    jpeg_mem_dest(&LOS_compress,&outbuffer,&outsize);

    LOS_compress.image_width = image.width();
    LOS_compress.image_height = image.height();
    LOS_compress.input_components = 3;
    LOS_compress.in_color_space = JCS_RGB;

    // 填充默认数据
    jpeg_set_defaults(&LOS_compress); 

    // 设置基准标准
    jpeg_set_quality(&LOS_compress,quality,true);
    
    jpeg_start_compress(&LOS_compress, true);


    int row = image.width() * 3;
    std::vector<unsigned char> row_buffer(row);


    while(LOS_compress.next_scanline < LOS_compress.image_height )
    {
        unsigned char* x_row_ptr = 
            reinterpret_cast<unsigned char*>(
                image.image()->data + (LOS_compress.next_scanline * image.image()->bytes_per_line)
            );
        
        for(int i = 0; i < image.image()->width; ++i)
        {
            row_buffer[i * 3 + 0] = x_row_ptr[i * 4 + 2];   // R
            row_buffer[i * 3 + 1] = x_row_ptr[i * 4 + 1];   // G
            row_buffer[i * 3 + 2] = x_row_ptr[i * 4 + 0];   // b
        }

        JSAMPROW row_pointer[1] = {row_buffer.data()};
        jpeg_write_scanlines(&LOS_compress, row_pointer, 1);
    }

    jpeg_finish_compress(&LOS_compress);

    std::vector<unsigned char> rst(outbuffer , outbuffer + outsize);

    return rst; 
}



