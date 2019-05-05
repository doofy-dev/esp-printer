#pragma once

/*
 * Joy: 5V
 *  X -> 33
 *  Y -> 34
 *  SW -> 35
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

//BME280 MicroSD card reader
#define SD_ADDRESS 0x76


//JOYSTICK
#define JOY_X 33
#define JOY_Y 34
#define JOY_SW 35

//Ignore in this range (+-value)
#define JOX_X_DEADZONE 0
#define JOX_Y_DEADZONE 0

//Minimum travel before scrolling
#define JOX_X_MIN_TO_SCROLL 0
#define JOX_Y_MIN_TO_SCROLL 0


//MISC
//FONT
#define FONT ArialMT_Plain_10
#define TEXT_ALIGN TEXT_ALIGN_LEFT
#define TEXT_COLOR WHITE
#define TEXT_PADDING_LEFT 5
#define TEXT_PADDING_TOP 5
#define TEXT_PADDING_RIGHT 5
#define TEXT_PADDING_BOTTOM 5
