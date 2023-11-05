// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int tring = 9;
int echo = 10;
int led = 6;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(tring, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(tring, LOW);
  delayMicroseconds(2);
  digitalWrite(tring, HIGH);
  delayMicroseconds(10);
  digitalWrite(tring, LOW);
  float ti = pulseIn(echo, HIGH);
  float distance = (ti * 0.034) / 2;
  Serial.print("Distance:");
  Serial.println(distance);
  lcd.setCursor(6, 0);
  lcd.print("cm");
  lcd.print(distance);
  delay(10);
  lcd.clear();
  int B = map(distance, 4, 30, 25, 0);
  if (distance > 30) {
    digitalWrite(led, LOW);
  } else if (distance < 4) {
    digitalWrite(led, HIGH);
  } else {
    analogWrite(led, B);
  }
}
