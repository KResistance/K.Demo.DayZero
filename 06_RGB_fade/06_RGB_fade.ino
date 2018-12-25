#include <FastLED.h> // this library helps us to control RGB leds

#define NUM_LEDS 1 // leds count
#define DATA_PIN 3 // data pin, connected to DIO
#define COLOR_ORDER GRB  //if your colors look incorrect, change the color order here
#define BRIGHTNESS  20 // 0-255
#define FRAMES_PER_SECOND 20 // control speed of animation

CRGB leds[NUM_LEDS]; // leds array
byte heatIndex = 0; // current gradient color position
int fadeAmount = 1; // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // setup our 'stripe'
  FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050); 
  // set brightness
  FastLED.setBrightness(BRIGHTNESS); // set brightness
}

// the loop routine runs over and over again forever:
void loop() {
  // set color of led. selected from gradient
  leds[0] = ColorFromPalette(RainbowColors_p , heatIndex);

  // calculate new heat
  heatIndex += fadeAmount;

  if (heatIndex <= 0 || heatIndex >= 255) {
    fadeAmount = -fadeAmount;
  }
  
  // check overflow
  if(heatIndex > 255)
    heatIndex = 255;
  if(heatIndex < 0)
    heatIndex = 0;

  // display this frame  
  FastLED.show(); 
  // control animation speed
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}
