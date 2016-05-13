#include <Adafruit_NeoPixel.h>
#define PIN 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void neoSetup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void setRed() {
  colorWipe(strip.Color(255, 0, 0), 200);
}

void setGreen() {
  colorWipe(strip.Color(0, 255, 0), 200);
}

void setBlue() {
  colorWipe(strip.Color(0, 0, 255), 200);
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  } 
}

void clearNeo() {
  strip.clear();
  strip.show();  
}

