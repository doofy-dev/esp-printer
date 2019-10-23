#pragma once
#include "configuration.h"
#include "Display.h"
#include <Arduino.h>
#include <OLEDDisplayUi.h>

struct DisplayString{
    int maxwidth;
    int scrollPos;
    String text;
    double lastScroll;

    DisplayString(String data, int maxWidth);

    String getText(OLEDDisplay &display);
};