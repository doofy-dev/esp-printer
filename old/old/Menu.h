#pragma once
#include "Singleton.h"
#include <vector>
#include <Wire.h>
#include <old/Display.h>

#include "Joystick.h"

//@TODO: Rename to something more meaningful
class MenuPoint;
class Menu{
    std::vector<MenuPoint*> menuPoints;
    MenuPoint* currentMenu = 0;
    MenuPoint* home = 0;
    Display *display;
    std::vector<MenuPoint*> history;
    int selected = 0;
public:
    Menu(Display *display);
    virtual void draw();
    virtual void processInput(Joystick *joystick);
    void addEntry(MenuPoint *p);
    void setHome(MenuPoint *p);
    void back();
};