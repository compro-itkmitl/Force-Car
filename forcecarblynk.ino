#include <ESP8266WiFi.h>
#include <NewPing.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "1f291d98308e4ae29ff935bac3a7f301";
char ssid[] = "srnds";
char pass[] = "893474870";

int pinB1 = 16; // D0 -> IN1
int pinB2 = 5; //  D1 -> IN2
int pinA1 = 4; // D2 -> IN3
int pinA2 = 0;  //  D3 -> IN4

int TRIG_PIN = D6; // D6 -> TRIG
int ECHO_PIN = D5; // D5 -> ECHO

NewPing sonar(TRIG_PIN, ECHO_PIN);

long distance;

boolean run = true;
boolean auto_run = false;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

BLYNK_WRITE(11) {
  if (param.asInt()) {
    forward(1);
  }
}

BLYNK_WRITE(12) {
  if (param.asInt()) {
    turnRight(1);
  }
}

BLYNK_WRITE(13) {
  if (param.asInt()) {
    backward(1);
  }
}

BLYNK_WRITE(14) {
  if (param.asInt()) {
    turnLeft(1);
  }
}

BLYNK_WRITE(15) {
  if (param.asInt()) {
    coast(200);
  }
}

BLYNK_WRITE(16) {
  if (param.asInt()) {
    auto_run = true;
  }else{
    auto_run = false;
    coast(1);
  }
}

void loop() {
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

  if(auto_run){
    distance = sonar.ping_cm();
    Serial.println(distance);
    Serial.print(" cm.\n");
     if (distance < 15 ) {
       backward(300);
       coast(300);
       turnRight(300);
       coast(300);
     }else{
       forward(1);
     }
  }
}


void forward(int time)
{
  motorAForward();
  motorBForward();
  delay(time);
}

void backward(int time)
{
  motorABackward();
  motorBBackward();
  delay(time);
}

void turnLeft(int time)
{
  motorABackward();
  motorBForward();
  delay(time);
}

void turnRight(int time)
{
  motorAForward();
  motorBBackward();
  delay(time);
}

void coast(int time)
{
  motorACoast();
  motorBCoast();
  delay(time);
}

void brake(int time)
{
  motorABrake();
  motorBBrake();
  delay(time);
}




void motorAForward()
{
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
}

void motorABackward()
{
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, HIGH);
}


void motorBForward()
{
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, LOW);
}

void motorBBackward()
{
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, HIGH);
}



void motorACoast()
{
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, LOW);
}

void motorABrake()
{
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, HIGH);
}

void motorBCoast()
{
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, LOW);
}

void motorBBrake()
{
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, HIGH);
}
