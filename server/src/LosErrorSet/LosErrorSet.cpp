

#include "LosErrorSet.h"
#include "logger.h"
#include <X11/Xlib.h>
#include <string>

int LosXErrorHandler(Display* d , XErrorEvent* e)
{
    char buf[256];
    XGetErrorText(d, e->error_code, buf, sizeof(buf));
    LOGE("X11 Error:" + std::string(buf) + "(Opcode:" + std::to_string(e->request_code) + ")");
    return 0;
}