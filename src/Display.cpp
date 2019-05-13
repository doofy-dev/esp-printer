#include "Display.h"
#include "configuration.h"

#include <Arduino.h>


void Display::init() {
    display = new SSD1306Wire(DISPLAY_ADDRESS, DISPLAY_SDA, DISPLAY_SCL);
    display->init();
    display->flipScreenVertically();
    display->setFont(FONT);
    display->setTextAlignment(TEXT_ALIGN);
    display->setColor(TEXT_COLOR);

    ui = new OLEDDisplayUi(display);
}

void Display::clear() {
    display->clear();
}

void Display::draw() {
    display->display();
}

void Display::string(int x, int y, String data) {
    display->drawString(x, y, data);
}

void Display::rect(int x, int y, int width, int height) {
    display->fillRect(x, y, width, height);
}

void Display::addLine(DisplayString *line) {
    lines.push_back(line);
}

void Display::empty() {
    for(auto line : lines){
        delete(line);
    }

    lines.clear();
}
