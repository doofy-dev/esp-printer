#pragma once
#include "Singleton.h"
#include <vector>
#include <Wire.h>
#include <Display.h>

#include "Joystick.h"
class MenuPoint;
class Menu{
    std::vector<MenuPoint*> menuPoints;
    MenuPoint* currentMenu = 0;
    Display *display;
    std::vector<MenuPoint*> history;
    int selected = 0;
public:
    Menu(Display *display);
    virtual void draw();
    virtual void processInput(Joystick *joystick);
    void addEntry(MenuPoint *p);
    void back();
};