#include <GxEPD2.h>
#include <GxEPD2_4C.h>
#include <GxEPD2_EPD.h>
#include <Fonts/FreeMonoBold9pt7b.h>

// epaper Definitions
#define BUSY 17
#define RST 7
#define DC 6
#define CS 10
#define CLK 12
#define MOSI 11
//#define BUTTON_PIN 2  // New: Button for display inversion
//#define EPD_WIDTH 512
//#define EPD_HEIGHT 368

GxEPD2_4C < GxEPD2_437c, GxEPD2_437c::HEIGHT> epd(GxEPD2_437c(/*CS=D8*/ CS, /*DC=D3*/ DC, /*RST=D4*/ RST, /*BUSY=D2*/ BUSY)); // Waveshare 4.37" 4-color


void epdInit() {
  epd.init(115200, true, 50, false);
  epd.setRotation(0);
  epd.setTextColor(GxEPD_BLACK);
  epd.setFont(&FreeMonoBold9pt7b);  
  epd.setFullWindow();
  Serial.println("E-paper initialized");
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Weather Display Booting...");
  SPI.begin(CLK, MISO, MOSI, CS);
  delay(500);
  epdInit();
  delay(500);
  //epd.display();

  // Draw display
  // Serial.println("Drawing to e-paper...");
  epd.fillScreen(GxEPD_WHITE);
  epd.setCursor(125,20);
  epd.setTextSize(1);
  epd.print("HOME DASHBOARD");
  //epd.drawRect(0, 0, screenW, screenH, GxEPD_BLACK);
  epd.display();
  // epd.hibernate();
  // //epdPower(LOW);
 
  // Serial.println("Entering deep sleep...");
  // esp_sleep_enable_ext0_wakeup(GPIO_NUM_2, 0); // Wake on button press
  // esp_sleep_enable_timer_wakeup(900LL * 1000000); // 15 min
  // esp_deep_sleep_start();
}

void loop() {
  // Empty - device will be in deep sleep
} 
