#pragma once

#include <Wire.h>

#include <SSD1306Wire.h>
#include <OLEDDisplayUi.h>
#include <vector>

#include "configuration.h"

class Display{
private:
    OLEDDisplayUi *ui;
    SSD1306Wire *display;
public:
    Display(){ init(); }
    void clear();
    void draw();
    void init();
    void string(int x, int y, String data);

    void rect(int x, int y, int width, int height);

};