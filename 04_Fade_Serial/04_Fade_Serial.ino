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

const int led = 3;           // PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is

// the setup routine runs once when you press reset:
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available()) {
    // read the most recent byte (which will be from 0 to 255):
    brightness = Serial.parseInt();
    // skip end of line:
    Serial.read();

    // set the brightness of the led pin:
    analogWrite(led, brightness);
    // print new state:
    Serial.print("Set brightness to ");
    Serial.println(brightness);
  }
  
}
