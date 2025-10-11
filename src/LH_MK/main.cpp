/**
 * LundayHangin Malayuang Kontroler (MK)
 * @file main.cpp
 * MCU: Arduino Nano ESP32
 * @author Lakan Haraya Dima
 * @details Placeholder skeleton code para sa MK
 */

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <esp_now.h>     // Placeholder para sa PS direct link (ESP-NOW)
#include "konstant.h"   // Mga konstant at makro ng sistema
// #include "controller.h" // joystik, pihitan, pindutan 
// #include "telemetry.h"  // Komunikasyong telemetriya (TX/RX)
// #include "display.h"  // Tanawing interface ng OLED/TFT

// -------------------------------------------
// SEKSIYON 1: DEKLARASYON AT ESTRUKTURA
// -------------------------------------------

// Control Packet Structure (ipapadala papuntang PS o TD)
struct ControlPacket{
  uint8_t flags;
  uint8_t thrust;
  uint8_t swiveller;
  uint8_t rudder;
  uint8_t elevator;
  uint8_t ballonet;
  // Magdagdag ng iba pang control fields dito
};

// Telemetry Packet Structure (ipapadala papuntang KL)
struct TelemetryPacket{
  uint8_t flags;
  uint8_t thrust;
  uint8_t swiveller;
  uint8_t rudder;
  uint8_t elevator;
  uint8_t ballonet;
  float batteryVoltage;
  float temperature;
  unsigned long uptime;
  uint8_t signalStrength;
  // Magdagdag ng iba pang telemetry fields dito
};

// Placeholder data
ControlPacket ctrl;
TelemetryPacket telem;

// Non-blocking timers
unsigned long lastCtrlSend = 0;
unsigned long lastTelemSend = 0;
unsigned long lastDispUpdate = 0;

// Time intervals (ms)
const unsigned long CTRL_INTERVAL = 1000;   // magpadala ng kontrol kada agwat oras
const unsigned long TELEM_INTERVAL = 1000; // magpadala ng telemetriya kada agwat oras
const unsigned long DISP_INTERVAL = 1000;   // i-update ang display kada agwat oras

// Magdeklara ng funsiyon
String timeStamp();



// -------------------------------------------
// SEKSIYON 2: MGA FUNSIYON NG KUNWARIANG INISYALISASYON
// -------------------------------------------

void initInputSystem() {
  Serial.print(timeStamp());
  Serial.println("    [MK] Nasimulan ang sistama ng input (kunwaring joystik/pindutan).");
}

void initCommSystems() {
  Serial.print(timeStamp());
  Serial.println("    [MK] Nasimulan ang mga sistema ng komunikasyon (kunwaring kawing).");
}

void initDisplay() {
  Serial.print(timeStamp());
  Serial.println("    [MK] Nasimulan ang sistema ng displey (kunwaring OLED/TFT).");
}

String timeStamp() {
  unsigned long ms = millis();
  unsigned long seconds = ms / 1000;
  unsigned long millisPart = ms % 1000;

  unsigned int hours = (seconds / 3600) % 24;
  unsigned int minutes = (seconds / 60) % 60;
  unsigned int secs = seconds % 60;

  char buf[32];
  sprintf(buf, "[%02u:%02u:%02u.%03lu]", hours, minutes, secs, millisPart);
  return String(buf);
}

// ------------------------------------------
// SEKSYON 3: KUNWARIANG PAGHAWAK NG INPUT
// ------------------------------------------

void readInputs() {
  // Simulated na pagbasa ng kontrolstik/pindutan
  ctrl.flags = 0x00;                // kunwaring sagisag
  ctrl.thrust = random(0, 255);     // urong-sulong
  ctrl.swiveller = random(0, 255);  // higa-tayo
  ctrl.rudder = random(0, 255);     // kaliwa-kanan
  ctrl.elevator = random(0, 255);   // baba-taas
  ctrl.ballonet = random(0, 255);   // impis-pintog
}

// ------------------------------------------
// SEKSYON 4: MGA KUNWARIANG TRANSMISYON NG DATOS
// ------------------------------------------

void sendControlToPS() {
  Serial.print(timeStamp());
  Serial.print(" [MK→PS] Pakete ng Kontrol: flg=");
  Serial.print(ctrl.flags); Serial.print(", thr=");
  Serial.print(ctrl.thrust); Serial.print(", swi=");
  Serial.print(ctrl.swiveller); Serial.print(", rud=");
  Serial.print(ctrl.rudder); Serial.print(", ele=");
  Serial.print(ctrl.elevator); Serial.print(", bal=");
  Serial.println(ctrl.ballonet);
}

void sendTelemetryToKL() {
  telem.batteryVoltage = 12.4 + (random(-5, 5) / 10.0);
  telem.temperature = 25.0 + random(-2, 2);
  telem.uptime = millis() / 1000;
  telem.signalStrength = random(80, 100);

  Serial.print(timeStamp());
  Serial.print(" [MK→KL] Pakete ng Telemetriya: flg=");
  Serial.print(ctrl.flags); Serial.print(", thr=");
  Serial.print(ctrl.thrust); Serial.print(", swi=");
  Serial.print(ctrl.swiveller); Serial.print(", rud=");
  Serial.print(ctrl.rudder); Serial.print(", ele=");
  Serial.print(ctrl.elevator); Serial.print(", bal=");
  Serial.print(ctrl.ballonet); Serial.print(", bat=");
  Serial.print(telem.batteryVoltage); Serial.print("V, tmp=");
  Serial.print(telem.temperature); Serial.print("°C, upt=");
  Serial.print(telem.uptime); Serial.println("s");
}

// ------------------------------------------
// SEKSIYON 5: KUNWARIANG PIDBAK NG DISPLEY
// ------------------------------------------

void updateDisplay() {
  Serial.print(timeStamp());
  Serial.println("    [MK] Naisapanahon ang displey (kunwaring datos).");
}

// -------------------------------------------
// SEKSIYON 6: PATAKDANG UBOD NG PROGRAMA
// -------------------------------------------

void setup() {
  Serial.begin(BAUD_RATE);
  delay(TIMEOUT_MS);
  printVersion("MK");

  initInputSystem();
  initCommSystems();
  initDisplay();
}

// -------------------------------------------
// SEKSIYON 7: PANGUNAHING LIKAW NA DI-HUMAHARANG
// -------------------------------------------

void loop() {
  unsigned long now = millis();

  // (1) Basahin ang mga input nang tuloy-tuloy
  readInputs();

  // (2) Paulit-ulit na magpadala ng control packet sa PS
  if (now - lastCtrlSend >= CTRL_INTERVAL) {
    sendControlToPS();
    lastCtrlSend = now;
  }

  // (3) Paulit-ulit na magpadala ng telemetry packet sa KL
  if (now - lastTelemSend >= TELEM_INTERVAL) {
    sendTelemetryToKL();
    lastTelemSend = now;
  }

  // (4) Paulit-ulit na isapanahon ang displey
  if (now - lastDispUpdate >= DISP_INTERVAL) {
    updateDisplay();
    lastDispUpdate = now;
  }

  // (5) Ang iba pang gawaing pangkaligiran ay puwedeng ipasok dito
  // hal., pagsusuri ng kalusugan ng komunikasyon, pagsasapanahon ng LED panghiwatig, atbp.
}