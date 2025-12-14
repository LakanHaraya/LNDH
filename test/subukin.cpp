#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS   D5
#define TFT_DC   D3
#define TFT_RST  D4
#define TFT_LED  D8

#define JOYB_X    A0    // Rudder
#define JOYB_Y    A1    // Elevator
#define JOYA_X    A2    // Swiveller
#define JOYA_Y    A3    // Thruster

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void drawHeaders();
void generateRandomData();
void displayData();

// update interval
unsigned long lastUpdate = 0;
const unsigned long UPDATE_INTERVAL = 150; // ms

// ---------- Data Structures ----------
struct ControllerCmd {
  String fmd; int thr; int swi; int rud; int ele; int fbt; int abt;
} cmd;

struct DroneFeedback {
  float spd; float pit; float rol; float yaw;
} fbk;

struct DroneTelemetry {
  float alt; float lat; float lon; int dir; float bat; float tmp;
} tel;

String msg_drn, msg_ctr, msg_dck, msg_gcs;

// ---------- Setup ----------
void setup() {
  Serial.begin(115200);
  pinMode(TFT_LED, OUTPUT);
  digitalWrite(TFT_LED, HIGH);

  pinMode(JOYB_X, INPUT); // Rudder
  pinMode(JOYB_Y, INPUT); // Elevator

  pinMode(JOYA_X, INPUT); // Swiveller
  pinMode(JOYA_Y, INPUT); // Thruster

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);

  tft.setTextSize(2);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setCursor(10, 8);
  tft.println("LNDH Daglinsapad");

  drawHeaders();
  randomSeed(analogRead(A0));
}

// ---------- Main Loop ----------
void loop() {
  unsigned long now = millis();
  if (now - lastUpdate >= UPDATE_INTERVAL) {
    lastUpdate = now;
    generateRandomData();
    displayData();
  }
}

// ---------- Draw column headers ----------
void drawHeaders() {
  tft.setTextSize(1);
  tft.setTextColor(ILI9341_CYAN);
  tft.setCursor(10, 30);   tft.print("UTOS");
  tft.setCursor(120, 30);  tft.print("PIDBAK");
  tft.setCursor(220, 30);  tft.print("TELEMETRIYA");

  // dividing lines
  tft.drawLine(100, 25, 100, 220, ILI9341_DARKGREY);
  tft.drawLine(200, 25, 200, 220, ILI9341_DARKGREY);
  tft.drawLine(0, 220, 320, 220, ILI9341_DARKGREY);
}

// ---------- Generate random dummy data ----------
void generateRandomData() {
  // controller commands
  String modes[] = {"AWTO", "MNWL", "ATBY"};
  cmd.fmd = modes[random(0, 3)];

  // ===============================
  // === THRUSTER AND SWIVELLER ====
  // =========== START =============

  // map joystick values to -45~45 degrees (center at 2048, fine-tuned by -4 offset)
  int deadzoneA = 50; // optional small range to ignore drift

  int joyAX = analogRead(JOYA_X);
  int joyAY = analogRead(JOYA_Y);

  int centeredAX = joyAX - 2048 + 90;
  int centeredAY = joyAY - 2048 + 90;

  // apply deadzone
  if (abs(centeredAX) < deadzoneA) centeredAX = 0;
  if (abs(centeredAY) < deadzoneA) centeredAY = 0;

  // scale to -45° ~ +45° (extra +1 to correct rounding)
  cmd.swi = map(centeredAX, -2048, 2047, -45, 45 + 1);
  cmd.thr = map(centeredAY, -2048, 2047, -45, 45 + 1);
  
  // ============ END ==============
  // === THRUSTER AND SWIVELLER ====
  // ===============================

  
  // ===============================
  // ===== RUDDER AND ELEVATOR =====
  // =========== START =============

  // map joystick values to -45~45 degrees (center at 2048, fine-tuned by -4 offset)
  int deadzoneB = 50; // optional small range to ignore drift
  int offsetBX = 90;
  int offsetBY = 90;

  int joyBX = analogRead(JOYB_X);
  int joyBY = analogRead(JOYB_Y);

  int centeredBX = joyBX - 2048 + offsetBX;
  int centeredBY = joyBY - 2048 + offsetBY;

  // apply deadzone
  if (abs(centeredBX) < deadzoneB) centeredBX = 0;
  if (abs(centeredBY) < deadzoneB) centeredBY = 0;

  // scale to -45° ~ +45° (extra +1 to correct rounding)
  cmd.rud = map(centeredBX, -2048, 2047, -45, 45 + 1);
  cmd.ele = map(centeredBY, -2048, 2047, -45, 45 + 1);
  
  // ============ END ==============
  // ===== RUDDER AND ELEVATOR =====
  // ===============================

  
  cmd.fbt = random(0, 100);
  cmd.abt = random(0, 100);

  // drone feedback
  fbk.spd = random(0, 3000) / 100.0;
  fbk.pit = random(-10, 11);
  fbk.rol = random(-10, 11);
  fbk.yaw = random(0, 360);

  // telemetry
  tel.alt = random(0, 2000) / 1.0;
  tel.lat = 14.50 + random(-50, 51) / 10000.0;
  tel.lon = 121.00 + random(-50, 51) / 10000.0;
  tel.dir = random(0, 360);
  tel.bat = 3.6 + random(0, 40) / 100.0;
  tel.tmp = 35 + random(0, 10);

  // messages
  String msgSet1[] = {"Tatag  ", "Aligid ", "Akyat  ", "Daong  "};
  String msgSet2[] = {"Kawing ", "Hanap  ", "Sabay  "};
  String msgSet3[] = {"Daong  ", "Karga  ", "Handa  "};
  String msgSet4[] = {"Tamlay ", "Aktibo ", "Limbag "};

  msg_drn = msgSet1[random(0, 4)];
  msg_ctr = msgSet2[random(0, 3)];
  msg_dck = msgSet3[random(0, 3)];
  msg_gcs = msgSet4[random(0, 3)];
}

// ---------- Display data in 3 columns ----------
void displayData() {
  // Clear main area
  tft.fillRect(0, 50, 320, 170, ILI9341_BLACK);

  tft.setTextSize(1);
  tft.setTextColor(ILI9341_WHITE);

  int y = 50;

  // ---- Column 1: Controller Commands ----
  tft.setCursor(5, y);   tft.printf("fmd:%s", cmd.fmd.c_str());
  tft.setCursor(5, y+=20); tft.printf("thr:%3d", cmd.thr);
  tft.setCursor(5, y+=20); tft.printf("swi:%3d", cmd.swi);
  tft.setCursor(5, y+=20); tft.printf("rud:%3d", cmd.rud);
  tft.setCursor(5, y+=20); tft.printf("ele:%3d", cmd.ele);
  tft.setCursor(5, y+=20); tft.printf("fbt:%3d", cmd.fbt);
  tft.setCursor(5, y+=20); tft.printf("abt:%3d", cmd.abt);

  // ---- Column 2: Drone Feedback ----
  y = 50;
  tft.setCursor(110, y);   tft.printf("spd:%4.1f", fbk.spd);
  tft.setCursor(110, y+=20); tft.printf("pit:%3.0f", fbk.pit);
  tft.setCursor(110, y+=20); tft.printf("rol:%3.0f", fbk.rol);
  tft.setCursor(110, y+=20); tft.printf("yaw:%3.0f", fbk.yaw);

  // ---- Column 3: Telemetry ----
  y = 50;
  tft.setCursor(210, y);   tft.printf("alt:%4.0f", tel.alt);
  tft.setCursor(210, y+=20); tft.printf("lat:%.4f", tel.lat);
  tft.setCursor(210, y+=20); tft.printf("lon:%.4f", tel.lon);
  tft.setCursor(210, y+=20); tft.printf("dir:%3d", tel.dir);
  tft.setCursor(210, y+=20); tft.printf("bat:%.2fV", tel.bat);
  tft.setCursor(210, y+=20); tft.printf("tmp:%.1fC", tel.tmp);

  // ---- Bottom: Status messages ----
  tft.fillRect(0, 222, 320, 18, ILI9341_BLACK);
  tft.setTextSize(1);
  tft.setTextColor(ILI9341_GREEN);
  tft.setCursor(2, 225);
  tft.printf("drn:%s  ctr:%s  dck:%s  gcs:%s",
             msg_drn.c_str(), msg_ctr.c_str(), msg_dck.c_str(), msg_gcs.c_str());

  Serial.printf("JOYA_X:%d SWI:%d | JOYA_Y:%d THR:%d\n", analogRead(JOYA_X), cmd.rud, analogRead(JOYA_Y), cmd.ele);

}
