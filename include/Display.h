#pragma once

#include "Singleton.h"

#include <Wire.h>

#include <SSD1306Wire.h>
#include <OLEDDisplayUi.h>

#include "configuration.h"

class Display : public Singleton{
private:
    OLEDDisplayUi *ui;
    SSD1306Wire *display;
protected:
    Display();
public:
    void clear();
    void draw();
    void init();

    void string(int x, int y, String data);

    void rect(int x, int y, int width, int height);

    void switchColor();
};