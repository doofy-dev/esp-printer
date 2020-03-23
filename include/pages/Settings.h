#pragma once

#include <Page.h>

class Settings : public Page{
private:
    int currentIndex;
public:
    Settings(Display *display, Joystick *input);
};