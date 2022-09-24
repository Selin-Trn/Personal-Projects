#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int servo180Pin = 9;
const int servo360Pin = 10;
const int resetPin = 8;
const int greenLED = 7;
const int blueLED = 6;

char timestamp[16];
signed short hr, min, sec, time, pos180, pos360;
int buttonState = 0;

Servo myservo180;
Servo myservo360;

void setup() {
  Serial.begin(9600);
  time = 21600; // The amount of time between feedings in seconds.  
  pos180 = 90; // Starting position of the lid servo
  pos360 = 90; // Starting position of the mixer servo
  
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.print("Time :");
  lcd.setCursor(0, 1);
  lcd.print("STARTING...");
  Serial.println("STARTING");
  delay(2000);
  myservo180.write(pos180);
  myservo180.attach(servo180Pin, 500, 2500);
  myservo360.write(0);
  myservo360.attach(servo360Pin, 500, 2500);
  spinServo(); // Making sure the mixer works
  
  pinMode(greenLED, OUTPUT); // Green LED lights up when reset/the kibble is poured down
  pinMode(blueLED, OUTPUT); // Blue LED lights up as long as the feeder works
  pinMode(resetPin, INPUT_PULLUP);
  
  digitalWrite(blueLED, HIGH);
}

void loop() {
  hr = time / 3600;
  min = (time % 3600)/60;
  sec = time % 60;
  lcd.setCursor(0, 1);
  sprintf(timestamp,"%0.2d : %0.2d : %0.2d     ",hr, min, sec); // LCD screen timer
  lcd.print(timestamp);
  Serial.println(timestamp);
  
  delay(1000);
  
  if ( time == 0) {
    turnServo();
    time = 21597;
  }
  resetFunc();  
  time--;
}

//SERVO FUNCTIONS

//360 degrees mixing servo
void spinServo() {
  myservo360.write(-pos360);
  delay(5000);
  myservo360.write(pos360);
}

//Main pouring function
void turnServo() {
  digitalWrite(greenLED, HIGH);
  Serial.println("POURING FOOD");
  delay(500);
  lcd.noBacklight(); // The LCD backlight turns off to maximize servo power

  for (int i = 0; i<3 ; i++) {
    myservo360.write(-pos360); // Mixer turns on
    delay(2000);
    myservo180.write(0); // Servo turns 90 degrees
    Serial.println("90 degrees turn");
    delay(100);
    
    delay(450); // 0.45 seconds delay to pour cat food
    
    myservo180.write(pos180); // Servo returns to its starting position
    Serial.println("-90 degrees turn");
    delay(1500);
  }
  delay(3000);
  myservo360.write(pos360); // Mixer turns off
  delay(500);
  digitalWrite(greenLED, LOW);
  lcd.backlight(); // LCD backlight back on
}

void resetFunc() {
  buttonState = digitalRead(resetPin);
  if(buttonState == LOW) {
    lcd.setCursor(0, 1);
    lcd.print("RESET...     ");
    Serial.println("RESET");
    delay(2000);
    turnServo();
    time = 21597; // The amount of time between feedings (time the servos spent working extracted)
  }
}
