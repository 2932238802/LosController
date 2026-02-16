

#include "LosErrorSet.h"


int LosXErrorHandler(Display* d , XErrorEvent* e)
{
    char buf[256];
    XGetErrorText(d, e->error_code, buf, sizeof(buf));
    LOGE("X11 Error:" + std::string(buf) + "(Opcode:" + std::to_string(e->request_code) + ")");
    return 0;
}