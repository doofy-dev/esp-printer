#include <configuration.h>
#include "Joystick.h"
#include <Arduino.h>

#include <cmath>

Joystick::Joystick() {
    pinMode(JOY_X, INPUT);
    pinMode(JOY_Y, INPUT);
//    pinMode(JOY_SW, INPUT);
    pinMode(JOY_SW, INPUT_PULLUP);
    digitalWrite(JOY_SW, HIGH);
}

void Joystick::update() {
    IClass::update();
    float x = analogRead(JOY_X) / 2048.0f - 1.0f;
    float y = analogRead(JOY_Y) / 2048.0f - 1.0f;
    int pressed = digitalRead(JOY_SW);
    mRelease = false;
    if (pressed == 0) {
        if (mPress) {
            mPress = false;
            mDown = true;
            mRelease = false;
            mClick = false;
        } else {
            mPress = true;
            mDown = false;
            mRelease = false;
            mClick = false;
        }
    } else {
        if (mPress) {
            mPress = false;
            mDown = false;
            mRelease = false;
            mClick = true;
        } else if (mDown) {
            mPress = false;
            mDown = false;
            mRelease = true;
            mClick = false;
        }
    }

    if (std::abs(x) > JOY_X_DEADZONE) {
        mDX = (x);
    } else {
        mDX = 0;
    }
    if (std::abs(y) > JOY_Y_DEADZONE) {
        mDY = (y);
    } else {
        mDY = 0;
    }
    double s = millis();

    if ((std::abs(mDX) >= JOY_X_MIN_TO_SCROLL || std::abs(mDY) >= JOY_Y_MIN_TO_SCROLL) &&
        (s - mLastScroll > MENU_RESPONSIVENESS_MS)) {
        mX = (mDX > 0 ? 1 : -1);
        mY = (mDY > 0 ? 1 : -1);
        mLastScroll = s;
    }else{
        mX = 0;
        mY = 0;
    }
}

bool Joystick::isClick() {
    bool res = mClick;
    mClick = false;
    return res;
}
