// author: Von Reid
// This program controls my personal LED lights with motion sensor(s)

#include "setup.h"

void setUp(); // while no motion is detected

void motionIsDetected(); // do this when there IS motion detected

void sleep(); // sleep after <x> amount of time door has remained shut

void motionWatch(); // loop through this for motion-detecting functinonality

short unsigned int ledPin = 4;         // LED pin is connected to 4
short unsigned int piezoBuzzerPin = 3; // Piezo Buzzer pin is connected to 3
short unsigned int pirSensorPin = 2;   // PIR Sensor pin is connected to 2

const short unsigned int outP = 0; // input const
const short unsigned int inP = 1;  // output const

int motionDetected = LOW; // start motionDetected as low (no motion detected)

void setUp()
{
    pinMode(ledPin, outP);         // LED is output
    pinMode(pirSensorPin, inP);    // PIR Sensor is input
    pinMode(piezoBuzzerPin, outP); // the buzzer is an output
    Serial.begin(9600);            // Set serial out if we want debugging
    delay(5000);                   // Allow time for the PIR Sensor to calibrate
}

void motionWatch()
{
    motionDetected = digitalRead(pirSensorPin); // Read the PIR sensor
    if (motionDetected == HIGH)                 // if motion is detected
    {
        motionIsDetected();
    }
    digitalWrite(ledPin, LOW);
    digitalWrite(piezoBuzzerPin, LOW);
}

int sleep()
{
    motionDetected = digitalRead(pirSensorPin); // Read the PIR sensor
    if (motionDetected != HIGH)
    {
        return 0;
    }
}

void motionIsDetected()
{
    digitalWrite(ledPin, HIGH);
    analogWrite(piezoBuzzerPin, 200);
    delay(100);
    analogWrite(ledPin, LOW);
    analogWrite(piezoBuzzerPin, 25);
    delay(100);
}