#include "Joystick.h"
#include <Arduino.h>
#include <iostream>
#include "configuration.h"

float Joystick::getX() {
    return dX;
}

int Joystick::getScrollX() {
    int val = scrollX;
    scrollX = 0;
    return val;
}

float Joystick::getY() {
    return dY;
}

int Joystick::getScrollY() {
    int val = scrollY;
    scrollY = 0;
    return val;
}

bool Joystick::pressed() {
    bool p = swPressed;
    swPressed = false;
    return p;
}

void Joystick::update() {
    float x = analogRead(JOY_X) / 2048.0f - 1.0f;
    float y = analogRead(JOY_Y) / 2048.0f - 1.0f;

    int pressed = digitalRead(JOY_SW);
    if (pressed == 0) {
        if (!swBlock) {
            swPressed = pressed == 0;
            swBlock = true;
        }
    } else {
        swPressed = false;
        swBlock = false;
    }
    if (std::abs(x) > JOY_X_DEADZONE) {
        dX = x;
    } else {
        dX = 0;
    }
    if (std::abs(y) > JOY_Y_DEADZONE) {
        dY = y;
    } else {
        dY = 0;
    }

    double s = millis();

    if ((std::abs(dX) >= JOY_X_MIN_TO_SCROLL || std::abs(dY) >= JOY_Y_MIN_TO_SCROLL) &&
        (s - lastScroll > MENU_RESPONSIVENESS_MS)) {
        scrollX = (dX > 0 ? 1 : -1);
        scrollY = (dY > 0 ? 1 : -1);
        lastScroll = s;
    }
}

Joystick::Joystick() {
    pinMode(JOY_X, INPUT);
    pinMode(JOY_Y, INPUT);
//    pinMode(JOY_SW, INPUT);
    pinMode(JOY_SW, INPUT_PULLUP);
    digitalWrite(JOY_SW, HIGH);
}
