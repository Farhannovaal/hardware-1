#pragma once

// ============================================================
// SmartDish - Pin Configuration
// ============================================================

// HC-SR04
#define TRIG_PIN 18
#define ECHO_PIN 19

// LCD I2C
#define LCD_SDA 21
#define LCD_SCL 22
#define LCD_ADDRESS 0x27

// LED
#define LED_PIN 2

// Relay
// Active LOW:
// LOW  = ON
// HIGH = OFF
#define RELAY_PIN 27

// Button
#define BUTTON_PIN 4

// Buzzer
#define BUZZER_PIN 15

// Potentiometer
#define POT_PIN 34

// DHT11
#define DHT_PIN 32
#define DHT_TYPE DHT11
