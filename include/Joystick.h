#pragma once

#include "IClass.h"

class Joystick : public IClass{
private:
    int mX=0;
    int mY=0;
    float mDX=0;
    float mDY=0;
    bool mClick = false;
    bool mPress = false;
    bool mDown = false;
    bool mRelease = false;
    double mLastScroll = 0;
public:
    Joystick();
    void update() override;

    int x(){ return mX;}
    int y(){ return mY;}
    float dX(){ return mDX;}
    float dY(){ return mDY;}

    bool isPressed(){ return mPress;}
    bool isClick();
    bool isDown(){ return mDown;}
    bool isRelease(){ return mRelease;}
};