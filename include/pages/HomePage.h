#pragma once

#include <Adafruit_BME280.h>
#include "../Page.h"

class HomePage : public Page{
    Adafruit_BME280 sensor;
public:
    HomePage(Display *display, Joystick *input, String name);
    void update() override;
};