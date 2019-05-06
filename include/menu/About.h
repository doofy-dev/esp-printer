#pragma once

#include "MenuPoint.h"
#include "../Display.h"

class About : public MenuPoint{
public:
    About();

    void draw(Display *display) override;

    void processInput(Joystick *joystick) override;

};