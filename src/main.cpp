#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <SPI.h>
#include "Display.h"
#include <Arduino.h>
#include <Menu.h>
#include <Joystick.h>
#include <menu/About.h>
#include "menu/MenuPoint.h"
Menu *menu;
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

/*
void checkI2C() {
    byte error, address;
    int nDevices;
    bool found = false;
    for (address = 1; address < 127; address++) {
        found = false;
        display.clear(); // clearing the display
        display.setColor(WHITE);
        display.drawString(0, 10, "checking address");
        display.drawString(0, 25, "0x");
        if (address < 16) {
            display.drawString(20, 25, "0");
            display.drawString(30, 25, String(address, HEX));
        }
        display.drawString(20, 25, String(address, HEX));

        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error == 0) {
            display.drawString(5, 45, "Found");
            found = true;
            nDevices++;
        } else if (error == 4) {
            display.drawString(5, 50, "Error");
        }
        display.display();
        if (found) {
            delay(1000);
        }
    }
}*/

void loop() {
    joystick->update();
    display->clear();
    menu->processInput(joystick);
    menu->draw();
    display->draw();
}