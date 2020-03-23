//
// Created by doofy on 2020-03-23.
//

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <pages/HomePage.h>
#include <cmath>
#include <utility>
#include "Display.h"

HomePage::HomePage(Display *display, Joystick *input, String name) : Page(display, input, std::move(name)) {
    sensor = Adafruit_BME280();
    sensor.begin(0x76);
    sensor.setSampling(
            Adafruit_BME280::MODE_NORMAL,
            Adafruit_BME280::SAMPLING_X2,
            Adafruit_BME280::SAMPLING_X16,
            Adafruit_BME280::SAMPLING_X16,
            Adafruit_BME280::FILTER_X16,
            Adafruit_BME280::STANDBY_MS_0_5
    );
    parent = nullptr;
}

void HomePage::update() {
    Page::update();
    float press = sensor.readPressure()/1000;
    press = std::floor(press*100)/100;

    mDisplay->string(10, 0, "Tmp.:");
    mDisplay->string(40, 0, String(sensor.readTemperature()));
    mDisplay->string(70, 0, "*C");
    mDisplay->string(10, 10, "Pres.:");
    mDisplay->string(40, 10, String(press));
    mDisplay->string(80, 10, "kPa");

    mDisplay->string(10, 20, "Hum:");
    mDisplay->string(40, 20, String(sensor.readHumidity()));
    mDisplay->string(70, 20, "%");

    if(mInput->isClick()){
        mDisplay->setPage(child);
    }
}

