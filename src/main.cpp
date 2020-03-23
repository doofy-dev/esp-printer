#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <SPI.h>
#include <Arduino.h>
#include <IClass.h>
#include <Joystick.h>
#include <Display.h>
#include <pages/HomePage.h>
#include <pages/Menu.h>

Joystick *input;
Display *display;
IClass *menu;

void setup() {
    Wire.begin();
    Serial.begin(115200);
    input=new Joystick();
    display=new Display();
    auto *p = new HomePage(display, input, "Homepage");
    p->setChild(new Menu(display, input, "Main menu", 6));
    display->setPage(p);
}

void loop() {
    input->update();
    display->beforeUpdate();
//    menu->update();
    display->update();
}