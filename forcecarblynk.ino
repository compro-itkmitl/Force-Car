//to use wifi we need to include ESP8266WiFi.h
//to use ultrasonic we need to include NewPing.h
//to use blynk application we need to include BlynkSimpleEsp8266.h
#include <ESP8266WiFi.h>
#include <NewPing.h>
#include <BlynkSimpleEsp8266.h>

//to use blynk application we need auth tokens from application
//and to connect with blynk on mobile we need ssid and password of wifi
//to connect and control a car from moblie
char auth[] = "343e76bc3b1642f79cf0732a095cb5e8"; //auth token from email
char ssid[] = "..."; //ssid from wifi (hotspot)
char pass[] = "meakmeak"; //password of wifi (hotspot)

int pinB1 = 16; // D0 -> IN1
int pinB2 = 5; //  D1 -> IN2
int pinA1 = 4; // D2 -> IN3
int pinA2 = 0;  //  D3 -> IN4

int TRIG_PIN = D6; // D6 -> TRIG
int ECHO_PIN = D5; // D5 -> ECHO

int buzzer = 2; // D4 -> BUZZER

int frequency = 50000; //frequency that make buzzer silent

//to use ultrasonic we must use this instruction to connect with port of ultrasonic
NewPing sonar(TRIG_PIN, ECHO_PIN);

//variable of distance of ultrasonic signal
long distance;

//variable to check the car working just fine
boolean run = true;

//variable to make auto mode work
boolean auto_run = false;

void setup() {
  //begin to connect with blynk and internet
  Blynk.begin(auth, ssid, pass);

  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

}

BLYNK_WRITE(11) {
  //by using blynk in button v11
  if (param.asInt()) {
    //if button pressed, make a car go forward
    forward(1);
  }
}

BLYNK_WRITE(12) {
  //by using blynk in button v12
  if (param.asInt()) {
    //if button pressed, make a car turn right
    turnRight(1);
  }
}

BLYNK_WRITE(13) {
  //by using blynk in button v13
  if (param.asInt()) {
    //if button pressed, make a car go backward
    backward(1);
  }
}

BLYNK_WRITE(14) {
  //by using blynk in button v14
  if (param.asInt()) {
    //if button pressed, make a car turn left
    turnLeft(1);
  }
}

BLYNK_WRITE(15) {
  //by using blynk in button v15
  if (param.asInt()) {
    //if button pressed, make a car stop
    coast(200);
  }
}

BLYNK_WRITE(16) {
  //auto mode for a car to ditect object
  //by using blynk in button v16
  if (param.asInt()) {
    auto_run = true;
    //if button pressed on, begin the auto mode
  }else{
    auto_run = false;
    coast(1);
    //if button pressed off, stop the auto mode
    //then stop
  }
  
}

void loop() {
  //this instuction is for checking the car that working just fine or not
  if (run) {
    for (int i = 0; i <= 500; i++) {
      delay(10);
    }
    forward(400);
    coast(200);
    backward(400);
    coast(200);
    turnLeft(400);
    coast(200);
    turnRight(400);
    coast(200);
    run = false;
  }
  Blynk.run();

  //this instuction is for begin the auto mode from blynk function
  if(auto_run){
    //if auto_run from v16 function pressed on begin the instuction
    distance = sonar.ping_cm();
    
    //display the distance between car and object to lcd
     if (distance < 15 ) {
       //if a car too close with object less than 15 cm
       //turn left
       turnLeft(300);
     }else{
      //if not, go forward
      forward(1);
    }
  }
}

void voice(int time){
  //make buzzer ring and silent per time
  distance = sonar.ping_cm();
  if (distance < 15 ) {
    tone(buzzer, 40000);
    delay(50);
    noTone(buzzer);
    delay(50);
  }else{
    tone(buzzer, 40000);
    delay(1000);
    noTone(buzzer);
    delay(1000);
    }
}

void forward(int time)
{
  //motors left & right rotate forward
  motorAForward();
  motorBForward();
  delay(time);
}

void backward(int time)
{
  //motors left & right rotate backward
  motorABackward();
  motorBBackward();  
  delay(time);
}

void turnLeft(int time)
{
  //motor left rotate forward
  //motor right rotate backward
  //(go left)
  motorABackward();
  motorBForward();
  delay(time);
}

void turnRight(int time)
{
  //motor left rotate forward
  //motor right rotate backward
  //(go right)
  motorAForward();
  motorBBackward();
  delay(time);
}

void coast(int time)
{
  //motor left & right stop slowly
  //wheels not locked
  motorACoast();
  motorBCoast();
  delay(time);
}

void motorAForward()
{
  //make right motor of wheel rotating to go forword
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
}

void motorABackward()
{
  //make right motor of wheel rotating to go backward
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, HIGH);
}


void motorBForward()
{
  //make left motor of wheel rotating to go forward
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, LOW);
}

void motorBBackward()
{
  //make left motor of wheel rotating to go backward
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, HIGH);
}

void motorACoast()
{
  //make right motor of wheel rotating to stop slowly
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, LOW);
}

void motorBCoast()
{
  //make left motor of wheel rotating to stop slowly
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, LOW);
}
