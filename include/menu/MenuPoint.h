#include <utility>

#pragma once

#include <Wire.h>
#include "Display.h"
#include "Joystick.h"
#include <Menu.h>

class MenuPoint {
private:
    String mName;
protected:
    Menu *parent = 0;
public:
    explicit MenuPoint(String name) : mName(std::move(name)) {}

    void setParent(Menu *m) { parent = m; }

    virtual void draw(Display *display) {}

    virtual void processInput(Joystick *joystick) {}

    String getName() { return mName; }
};