


#pragma  once

#include<X11/X.h>
#include <X11/Xlib.h>
#include<string>
#include<iostream>
#include"logger.h"

#undef Status
#undef Success

int LosXErrorHandler(Display* d , XErrorEvent* e);