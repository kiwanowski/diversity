#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>

#define BLACK 0
#define WHITE 1

#define WIDTH 400
#define HEIGHT 240

#define SHARP_SCK  18
#define SHARP_MOSI 23
#define SHARP_SS   5

Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 400, 240);

void setup() {
  display.begin();
  display.clearDisplay();
  display.setRotation(0);
}

void loop() {
  display.fillScreen(BLACK);
  display.setTextSize(12);
  display.setTextColor(WHITE);
  display.setCursor(25, 60);
  display.println("12:12");
  display.setTextSize(4);
  display.setCursor(25, 160);
  display.println("12.12.12");
  display.refresh();
}
