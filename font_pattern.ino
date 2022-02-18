/**
 * Font patterning
 * 
 * Images formed by drawing 100 overlapped characters onto the screen.
 * The pixelated font and negative spaces form new patterns.
 *
 * Requires:
 * - Arduino
 * - ILI9341 OLED screen (Adafruit shield available)
 * 
 * by: Colin Drake
 * version: 1.0
 */
  
#include <Adafruit_ILI9341.h>
#include <Adafruit_GFX.h>

// OLED setup.
Adafruit_ILI9341 tft = Adafruit_ILI9341(10, 9);

void setup() {
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
}

void loop() {
  // Draw 100 random characters.
  for (int i = 0; i < 100; i++) {
    tft.drawChar((int) random(tft.width()),
                 (int) random(tft.height()),
                 (char) random(255),
                 ILI9341_WHITE,
                 ILI9341_BLACK,
                 10 + (int) random(10));
  }

  // Hold for 30 seconds then clear, pause, and re-loop().
  delay(30 * 1000);
  tft.fillScreen(ILI9341_BLACK);
  delay(2 * 1000);
}
