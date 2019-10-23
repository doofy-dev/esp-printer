#pragma once


#include "old/Singleton.h"

class Joystick {
private:
    float prevX = 0;
    float prevY = 0;

    float dX, dY;
    bool swPressed = false;
    bool swBlock = false;
    double lastScroll = 0;
    int scrollX, scrollY;
public:
    float getX();

    float getY();

    void update();

    int getScrollX();

    int getScrollY();

    bool pressed();

    Joystick();
};