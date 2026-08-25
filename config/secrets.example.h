#pragma once

// ============================================================
// SmartDish - Secrets Example
//
// Copy this file to:
//
// config/secrets.h
//
// Then fill in the real credentials.
//
// DO NOT PUT REAL CREDENTIALS HERE.
// ============================================================

#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

#define MQTT_USERNAME "YOUR_MQTT_USERNAME"
#define MQTT_PASSWORD "YOUR_MQTT_PASSWORD"

#define MQTT_CA_CERT R"EOF(
-----BEGIN CERTIFICATE-----
YOUR_CA_CERTIFICATE
-----END CERTIFICATE-----
)EOF"
