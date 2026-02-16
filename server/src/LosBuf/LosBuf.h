
#pragma once
#include <cstdlib>

class LosBuf{
    
public:
    LosBuf(unsigned char**);
    ~LosBuf();

    LosBuf(const LosBuf&) = delete;
    LosBuf& operator=(const LosBuf&) = delete;
private:
    unsigned char** LOS_buffer;
};

