#include "old/Display.h"
#include "configuration.h"

#include <Arduino.h>


void _Display::init() {
    _Display = new SSD1306Wire(_Display_ADDRESS, _Display_SDA, _Display_SCL);
    _Display->init();
    _Display->flipScreenVertically();
    _Display->setFont(FONT);
    _Display->setTextAlignment(TEXT_ALIGN);
    _Display->setColor(TEXT_COLOR);

    ui = new OLED_DisplayUi(_Display);
}

void _Display::clear() {
    _Display->clear();
}

void _Display::draw() {
    _Display->_Display();
}

void _Display::string(int x, int y, String data) {
    _Display->drawString(x, y, data);
}

void _Display::rect(int x, int y, int width, int height) {
    _Display->fillRect(x, y, width, height);
}

void _Display::addLine(_DisplayString *line) {
    lines.push_back(line);
}

void _Display::empty() {
    for(auto line : lines){
        delete(line);
    }

    lines.clear();
}
