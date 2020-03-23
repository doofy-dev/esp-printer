#pragma once
#include <vector>
#include <Wire.h>
#include "Display.h"

#include "Joystick.h"

class MenuPoint;
class Menu{
    Display *display;
public:
    Menu(Display *display);
};