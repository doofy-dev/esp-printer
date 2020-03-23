#pragma once
#include <vector>
#include <Wire.h>
#include "Display.h"

#include "Joystick.h"

class MenuPoint;
class Menu{
    std::vector<MenuPoint*> menuPoints;
    Display *display;
    Joystick *joystick;
    std::vector<MenuPoint*> history;
    int selected = 0;
public:
    Menu(Display *display, Joystick *joystick);
    virtual void draw();
    virtual void update();
    void addEntry(MenuPoint *p);
};