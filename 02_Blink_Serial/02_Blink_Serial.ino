/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// 5V - 100 Om
// 3.3V - 10 Om

int LED = LED_BUILTIN;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available()) {
    // read the string intil \n:
    String command  = Serial.readStringUntil('\n');

    // try to find a known command  
    if(command == String("on")){
        digitalWrite(LED, HIGH);
        Serial.println("Led state is ON");
    }
    else if(command == "off"){
        digitalWrite(LED, LOW);
        Serial.println("Led state is OFF");
    }
    // or print a wrong command to serial
    else{
      Serial.println("Unknown command: " + command + " Use 'on' or 'off' commands");
      }
  }
}
