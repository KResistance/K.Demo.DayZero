/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

// 5V - 100 Om
// 3.3V - 10 Om

const int led = 5;           // PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 6 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of the led pin:
  analogWrite(led, brightness);

  // reverse the direction of the fading at the end of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  // change the brightness for the next time through the loop:
  brightness = brightness + fadeAmount;

  // check overflow
  if(brightness > 255)
    brightness = 255;
  if(brightness < 0)
    brightness = 0;

  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
