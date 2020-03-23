#pragma once
#define NAME "ESP 3DBoard"
#define VERSION "0.0.1"
/*
 * Joy: 5V
 *  X -> 32
 *  Y -> 33
 *  SW -> 26
 *
 * SD: 5V
 *  CS -> 5 (SS)
 *  SCK -> 18
 *  MISO -> 19
 *  MOSI -> 23
 *
 * OLED: 3V
 *  SCL -> 21
 *  SDA -> 22
 *
 * Sensor: 5V
 *  SCK/SCL -> 21
 *  SDA/SDI -> 22
 */

//SSD12306 I2c pins and address
#define DISPLAY_ADDRESS 0x3c
#define DISPLAY_SDA 22
#define DISPLAY_SCL 21
#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 64

//BME280 Sensor I2C address
#define BME280_ADDRESS 0x76


//JOYSTICK
#define JOY_X 32
#define JOY_Y 33
#define JOY_SW 26

//Ignore in this range (+-value)
#define JOY_X_DEADZONE 0.2
#define JOY_Y_DEADZONE 0.2

//Minimum travel before scrolling
#define JOY_X_MIN_TO_SCROLL 0.5
#define JOY_Y_MIN_TO_SCROLL 0.5


//MISC
//FONT
#define FONT ArialMT_Plain_10
#define HEADER_SIZE 12
#define FONT_SIZE 10 //equalt to the font
#define TEXT_ALIGN TEXT_ALIGN_LEFT
#define TEXT_COLOR INVERSE

//IO
#define MENU_RESPONSIVENESS_MS 250 //scroll speed milisec delay
//SD card settings
#define SD_CONFIG_FILE "config.ini"
#define SD_WEBUI_FOLDER "www"
#define SD_UPLOAD_FOLDER "upload"

#define LANGUAGE "en"