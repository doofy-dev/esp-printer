#include "config.h"
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <SSD1306.h> // alias for `#include "SSD1306Wire.h"`

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
//#include <Adafruit_BMP280.h>
#include <SPI.h>
#include <WiFi.h>

const uint8_t SD_CHIP_SELECT_PIN = 5;

#include <SPI.h>
#include <SD.h>

const char *ssid = "";
const char *password = "";


Adafruit_BME280 bme;
SSD1306 display(0x3c, 22, 21);
bool cardOk;


void setup() {
    Wire.begin();
    Serial.begin(9600);
    // put your setup code here, to run once:
    display.init();
    bool status;

    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_LEFT);

    WiFi.begin(ssid, password);

    display.clear(); // clearing the display

    display.setColor(WHITE);

//    bme.init();
    status = bme.begin(0x76);
    if (!status) {
        display.drawString(10, 30, "no sensor");

    }

    cardOk = SD.begin();
    display.display();
}

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
            /* Serial.print("Unknown error at address 0x");
             if (address < 16)
                 Serial.print("0");
             Serial.println(address, HEX);*/
        }
        display.display();
        if (found) {
            delay(1000);
        }
    }
}

void loop() {
    display.clear(); // clearing the display

    display.setColor(WHITE);

    if (WiFi.status() != WL_CONNECTED) {
        display.drawString(5, 0, "no network");
    } else {
        display.drawString(5, 0, WiFi.localIP().toString());
    }
    display.drawString(5, 10, String(bme.readTemperature()));
    display.drawString(5, 20, String(bme.readPressure() / 101325.0F) + String("atmos"));
    display.drawString(5, 30, String(bme.readHumidity()) + String("%"));
    if (cardOk) {
        String type;
        switch (SD.cardType()) {
            case CARD_MMC:
                type = "MMC";
                break;
            case CARD_SD:
                type = "SD";
                break;
            case CARD_SDHC:
                type = "SDHC";
                break;
            default:
                type = "Unknown";
        }
        display.drawString(5, 40, String("SD card type: ") + type);


        display.drawString(5, 50, String("Size: ") + String(SD.cardSize() / (1024.0f * 1024 * 1024)) + String("Gb"));

    } else {
        display.drawString(5, 40, String("NO SD"));
    }
    display.display();

}