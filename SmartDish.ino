#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <DHT.h>

#include "config/device_config.h"
#include "config/pin_config.h"
#include "config/mqtt_config.h"
#include "config/secrets.h"

// ============================================================
// Hardware Objects
// ============================================================

LiquidCrystal_I2C lcd(
    LCD_ADDRESS,
    16,
    2
);

DHT dht(
    DHT_PIN,
    DHT_TYPE
);

// ============================================================
// Network Objects
// ============================================================

WiFiClientSecure espClient;

PubSubClient mqtt(
    espClient
);

// ============================================================
// System State
// ============================================================

bool isSystemOn = true;
bool isOutputOn = false;
bool lastButtonState = HIGH;

// ============================================================
// Gesture State
// ============================================================

enum GestureState {
    WAITING,
    HAND_NEAR,
    HAND_AWAY
};

GestureState gestureState = WAITING;

// ============================================================
// Sensor State
// ============================================================

float distance = -1;
float lastDistance = -1;

float temperature = NAN;
float humidity = NAN;

// ============================================================
// Gesture Configuration
// ============================================================

const float HAND_NEAR_DISTANCE = 15.0;
const float HAND_AWAY_DISTANCE = 40.0;

// ============================================================
// Timing
// ============================================================

unsigned long lastSensorRead = 0;
unsigned long lastGestureTime = 0;
unsigned long lastLCDUpdate = 0;
unsigned long lastWiFiCheck = 0;
unsigned long lastMQTTAttempt = 0;
unsigned long lastTelemetry = 0;
unsigned long lastDHTRead = 0;

const unsigned long SENSOR_INTERVAL = 80;
const unsigned long GESTURE_COOLDOWN = 1000;
const unsigned long LCD_INTERVAL = 250;
const unsigned long WIFI_CHECK_INTERVAL = 5000;
const unsigned long MQTT_RETRY_INTERVAL = 5000;
const unsigned long TELEMETRY_INTERVAL = 5000;
const unsigned long DHT_INTERVAL = 2000;

// ============================================================
// Potentiometer
// ============================================================

int potValue = 0;
int brightness = 0;

// ============================================================
// Setup
// ============================================================

void setup() {

    Serial.begin(115200);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(RELAY_PIN, OUTPUT);

    digitalWrite(TRIG_PIN, LOW);
    digitalWrite(LED_PIN, LOW);

    dht.begin();

    Wire.begin(
        LCD_SDA,
        LCD_SCL
    );

    lcd.init();
    lcd.backlight();
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("SMARTDISH");

    lcd.setCursor(0, 1);
    lcd.print("SYSTEM READY");

    Serial.println();
    Serial.println("==============================");
    Serial.println("       SMARTDISH SYSTEM");
    Serial.println("==============================");
    Serial.println("SYSTEM READY");
    Serial.println();

    connectWiFi();

    Serial.println("Initializing MQTT TLS...");

    espClient.setCACert(
        MQTT_CA_CERT
    );

    mqtt.setServer(
        MQTT_SERVER,
        MQTT_PORT
    );

    delay(1000);
}

// ============================================================
// Loop
// ============================================================

void loop() {

    // Temporary
    // Logic lama akan kita pindahkan bertahap.

}
