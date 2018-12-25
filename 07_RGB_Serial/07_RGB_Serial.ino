#include <FastLED.h> // this library helps us to control RGB leds

#define NUM_LEDS 1 // leds count
#define DATA_PIN 3 // data pin, connected to DIO
#define COLOR_ORDER GRB  //if your colors look incorrect, change the color order here
#define BRIGHTNESS  20 // 0-255

CRGB leds[NUM_LEDS]; // leds array
int colors[] = {0, 0, 0};

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // setup our 'stripe'
  FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); 
  // set brightness
  FastLED.setBrightness(BRIGHTNESS); // set brightness
}

// the loop routine runs over and over again forever:
void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    // read 3 integers:
    for(int i = 0; i < 3; i++)
      colors[i] = Serial.parseInt();
    // wait end of line:
   if (Serial.read() == '\n') {
    // print parsed values:
     Serial.print("Set color: "); 
     Serial.print(colors[0]);
     Serial.print(";");
     Serial.print(colors[1]);
     Serial.print(";");  
     Serial.print(colors[2]);
     Serial.print(";");
     Serial.print("\n");    
    // set new color:
     leds[0] = CRGB(colors[0], colors[1], colors[2]);
     FastLED.show();
   }   
  }  
}
