#pragma once

#include "MenuPoint.h"
#include "old/Display.h"

class About : public MenuPoint{
public:
    About();

    void draw(Display *display) override;

    void processInput(Joystick *joystick) override;

};