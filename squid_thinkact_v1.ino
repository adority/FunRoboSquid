/**
 * Sprint 2 Code Outline
 * Think/Act
 * SquidBot
 * Outline of code for sprint 2
 * Mission: Drive straight to buoy, turn in circle, drive to next buoy, etc.,
 *          then back home
 * Team Squid: Aubrey, Diego, Gretchen, Jon, MJ, Paul  
 * 10/25/2017
 * Version 1
 */

//libraries included to use PixyCam
#include <SPI.h>  
#include <Pixy.h>

//library included to use servos
#include<Servo.h>

//libraries included to use motor and motion shield
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include "NineAxesMotion.h" 


//Constants and Global Variables VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
Pixy pixy; //creates PixyCam object to use
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); //creates motor shield

//eStop True if eStop activated
//flood True if hull flooding
//temp true if electronics overheating
boolean eStop, flood, temp = False;

//pins
const int FIN1 = 3; //right fin
const int FIN2 = 9; //left fin
const int VALVE1 = 10; //right valve
const int VALVE2 = 11; //left valve
const int STOP = 4; //pin to determine estop for interrupt

Servo FIN1,FIN2,TUBE1,TUBE2; //Servo objects to set up

//Constants
const int finCenter = 90;
const int tubeBent = 180;
const int tubeStraight = 0;

//DC motor
Adafruit_DCMotor *pump = AFMS.getMotor(1); //create bilge pump DC motor plugged into motor shield

//hold info about mission
int mission = 0; //entire mission in form '0123' = "Blue Red Green Home"
int currentState = 0; //current buoy going to in form '1' = 'Red'

//array to hold info about every bouy
//c=colour, x=x pos, y=y pos, s=size
//1=blue, 2=green, 3=red, 4=home
array = [(int c1=0, int x1=0, int y1=0, int s1=0),
          (int c2=0, int x2=0, int y2=0,int s2=0),
          (int c3=0, int x3=0, int y3=0, int s3=0),
          (int c4=0, int x4=0, int y4=0, int s4=0)];


//SETUP ROBOT CODE (RUN ONCE)SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
void setup() {
  Serial.begin(9600);
  pixy.init();
  
  rightFin.attach(FIN1);
  leftFin.attach(FIN2);
  rightValve.attach(VALVE1);
  leftValve.attach(VALVE2);

  attachInterrupt(digitalPinToInterrupt(STOP), eStop, CHANGE);

  //systemCheck
  //waitForLaunch

}

//ROBOT CONTROL LOOP (RUNS UNTIL STOP)LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
void loop() {
  //downloadMission
  //readSenseArduino

  //THINK
  //ACT
          
//TODO attach tube servos in setup

  switch(instruction) {

    case 0: //eStop
    break;
    case 1: //Follow direction
    break;
    case 2: //STRAIGHT
    digitalWrite(VALVE1, HIGH);
    digitalWrite(VALVE2, HIGH);
    TUBE1.write(tubeStraight);
    TUBE2.write(tubeStraight);
    FIN1.write(finCenter + function(timer));
    FIN2.write(finCenter + function(timer));
    break;
    case 3: //LEFT
    digitalWrite(VALVE1, HIGH);
    digitalWrite(VALVE2, HIGH);
    TUBE1.write(tubeBent);
    TUBE2.write(tubeStraight);
    FIN1.write(finCenter);
    FIN2.write(finCenter + function(timer));
    break;
    case 4: //NONE
    digitalWrite(VALVE1, LOW);
    digitalWrite(VALVE2, LOW);
    TUBE1.write(tubeBent);
    TUBE2.write(tubeBent);
    FIN1.write(finCenter);
    FIN2.write(finCenter);
    break;
    case 5: //systemCheck
    break;
    //TODO: create wing motion function and set up timer

}
}

//CONTROL FUNCTIONS CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC

//THINK
//determinePos
//determineDir
//determineSpeed

//ACT
//goToBuoy
//spin
//goHome
//dance

//eStop
//systemCheck
