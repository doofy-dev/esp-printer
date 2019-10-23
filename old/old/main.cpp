#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <SPI.h>
#include "old/Display.h"
#include <Arduino.h>

#include <Joystick.h>

//Menu *menu;
Joystick *joystick;
Display *display;

void setup() {
    Wire.begin();


    Serial.begin(115200);
    joystick = new Joystick;
    display = static_cast<Display *>(Display::getInstance());
    display->init();

    menu = new Menu(display);
    menu->addEntry(new MenuPoint("Printer"));
    menu->addEntry(new MenuPoint("Files"));
    menu->addEntry(new MenuPoint("WiFi"));
    menu->addEntry(new MenuPoint("Tools"));
    menu->addEntry(new About());
}

void loop() {
    joystick->update();
    display->clear();
    menu->processInput(joystick);
    menu->draw();
    display->draw();
}