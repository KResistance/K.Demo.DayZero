#include <FastLED.h> // this library helps us to control RGB leds

#define NUM_LEDS 1 // leds count
#define DATA_PIN 3 // data pin, connected to DIO
#define COLOR_ORDER GRB  //if your colors look incorrect, change the color order here
#define BRIGHTNESS  20 // 0-255

CRGB leds[NUM_LEDS]; // leds array

// the setup routine runs once when you press reset:
void setup() {
  // setup our 'stripe'
  FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); 
  // set brightness
  FastLED.setBrightness(BRIGHTNESS); // set brightness
}

// the loop routine runs over and over again forever:
void loop() {
      // Turn the first led red for 1 second
      leds[0] = CRGB::Red; 
      FastLED.show();
      delay(1000);
      
      // Set the first led back to black for 1 second
      leds[0] = CRGB::Black;
      FastLED.show();
      delay(1000);
}
