#include <Servo.h>
Servo myservo;

#include <Keypad.h>

// Servo
int angle = 0;
int i;
int c;

// LEDs/Shift Register
int tDelay = 1000; // 450
int latchPin = 11;
int clockPin = 10;
int dataPin = 12;
byte leds = 0;

// Button Matrix
const byte ROWS = 3;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  {'0', '1', '2'},
  {'3', '4', '5'},
  {'6', '7', '8'}
};

byte rowPins[ROWS] = {2, 3, 4};
byte colPins[COLS] = {5, 6, 7};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}


void setup() {

  myservo.attach(9);
  myservo.write(angle);

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(13, OUTPUT);

  leds = 0;
  updateShiftRegister();
  digitalWrite(13, LOW);

  Serial.begin(9600);

}


void loop() {

  // Tests
  //  leds = 0;
  //  updateShiftRegister();
  //  digitalWrite(13, LOW);
  //  delay(tDelay);

  //  for (i = 0; i < 10; i++) {
  //    angle += 10;
  //    myservo.write(angle);
  //    delay(500);
  //  }
  //
  //  for (i = 0; i < 10; i++) {
  //    angle -= 10;
  //    myservo.write(angle);
  //    delay(500);
  //  }
  //
  //  delay(3000);
  //
  //  for (i = 8; i >= 0; i--) {
  //    bitSet(leds, i);
  //    updateShiftRegister();
  //    delay(tDelay);
  //  }

  //  pinMode(13, OUTPUT);
  //  digitalWrite(13, HIGH);
  //  delay(tDelay);

  char customKey = customKeypad.getKey();
  i = 8 - (static_cast<int>(customKey) - 47);
  if (customKey) {
    Serial.println(customKey);
    Serial.println(i);
    if (i == -1) {
      if (digitalRead(13) == HIGH) {
        digitalWrite(13, LOW);
        angle -= 5;
        myservo.write(angle);
      } else {
        digitalWrite(13, HIGH);
        angle += 5;
        myservo.write(angle);
      }
    } else {
      if (bitRead(leds, i) == 1) {
        bitClear(leds, i);
        angle -= 5;
        myservo.write(angle);
      } else {
        bitSet(leds, i);
        angle += 5;
        myservo.write(angle);
      }
    }
    updateShiftRegister();
    delay(tDelay);
  };

  if (angle >= 30) {
    angle = 0;
    myservo.write(angle);
    delay(200);
    angle = 20;
    myservo.write(angle);
    delay(5000);
    angle = 0;
    myservo.write(angle);
    delay(tDelay);

    leds = 0;
    updateShiftRegister();
    digitalWrite(13, LOW);
  }

}
