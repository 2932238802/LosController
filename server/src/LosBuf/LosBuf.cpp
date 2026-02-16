#include "LosBuf.h"


/**
26_2_16
*/
LosBuf::LosBuf(unsigned char** buf):
    LOS_buffer(buf)
{}


/**
26_2_16
- 析构
*/
LosBuf::~LosBuf(){
    if(
        nullptr != LOS_buffer
        &&
        nullptr != *LOS_buffer
    ) 
    {
        free(*LOS_buffer);
        *LOS_buffer = nullptr;
    }
}


