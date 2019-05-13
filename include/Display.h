#pragma once

#include "Singleton.h"

#include <Wire.h>

#include <SSD1306Wire.h>
#include <OLEDDisplayUi.h>
#include <vector>

#include "configuration.h"
#include "DisplayString.h"

class Display : public Singleton{
private:
    OLEDDisplayUi *ui;
    SSD1306Wire *display;
    std::vector<DisplayString *> lines;
protected:
    Display();
public:
    void clear();
    void draw();
    void init();
    void addLine(DisplayString *line);
    void empty();

    void string(int x, int y, String data);

    void rect(int x, int y, int width, int height);

    void switchColor();
};