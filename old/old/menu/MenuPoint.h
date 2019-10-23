#pragma once

#include <utility>
#include <Wire.h>
#include "old/Display.h"
#include "Joystick.h"
#include <old/Menu.h>


//@TODO: Rename to something more meaningful
class MenuPoint {
private:
    String mName;
protected:
    MenuPoint *parent = 0;
    MenuPoint *active = 0;
    int selectOrBack = 0;
public:
    explicit MenuPoint(String name) : mName(std::move(name)) {}

    virtual void setParent(MenuPoint *m) { parent = m; }

    void draw(Display *display);
    virtual void render(Display *display){}

    void processInput(Joystick *joystick);
    virtual bool input(Joystick *joystick){ return false;}
    virtual String getName() { return mName; }

    void back();

};