/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Clawbot Competition Template                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ClawMotor            motor         3               
// ArmMotor             motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

const float WHEEL_DIAMETER = 4.03; // inches
const float WHEEL_CIRCUMFERENCE = WHEEL_DIAMETER * 3.1416;
const float GEAR_RATIO = 1; // 0.5 turn of motor = 1 turn of wheel
const int  AUTON_DRIVE_PCT = 50; // motors at 50% power during auton

void driveForward( float inches ) {
    float inchesPerDegree = WHEEL_CIRCUMFERENCE / 360;
    float degrees = inches / inchesPerDegree;    // startRotate doesn't wait for completion
    // this way, the other wheel can turn at same time
    front_left.startRotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct);
    front_right.startRotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct);
    rear_left.startRotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg, 
       AUTON_DRIVE_PCT, vex::velocityUnits::pct);    
    rear_right.rotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct);
}


void ControllerL1Pressed(){
  Intake1.spin(forward);
  Intake2.spin(forward);
  waitUntil(!Controller1.ButtonL1.pressing());
  // Stop the motor
  Intake1.stop();
  Intake2.stop();

}

void ControllerL2Pressed(){
  Intake1.spin(reverse);
  Intake2.spin(reverse);
  waitUntil(!Controller1.ButtonL2.pressing());
  // Stop the motor
  Intake1.stop();
  Intake2.stop();
  

}

void ControllerR1Pressed() {
  // Open the ClawMotor.
  
  flywheel_group.spin(forward);
  // Wait until R1 is released.
  waitUntil(!Controller1.ButtonR1.pressing());
  // Stop the motor
  flywheel_group.stop();

 
  

}
void ControllerR2Pressed() {
  // Close the ClawMotor.
  lancher.setVelocity(50, percent);
  lancher.spin(reverse);
  // Wait until R1 is released.
  waitUntil(!Controller1.ButtonR2.pressing());
  // Stop the motor
  lancher.stop();
}

void ControllerXPressed(){
  Roller.spin(forward);
  waitUntil(!Controller1.ButtonX.pressing());
  // Stop the motor
  Roller.stop();
}

  void ControllerAPressed(){
  Roller.spin(reverse);
  waitUntil(!Controller1.ButtonA.pressing());
  // Stop the motor
  Roller.stop();
}
void ControllerYPressed(){
  waitUntil(!Controller1.ButtonY.pressing());
  DigitalOutH.set(true);
  DigitalOutG.set(true);
  //waitUntil(!Controller1.ButtonY.pressing());
  // Stop the motor
  
}
void ControllerUpPressed(){
  spooderman.setVelocity(80,percent);
  spooderman.spin(forward);
  spooderman.setStopping(hold);
  waitUntil(!Controller1.ButtonUp.pressing());
  // Stop the motor
  spooderman.stop();
}
void ControllerDownPressed(){
  spooderman.spin(reverse);
  waitUntil(!Controller1.ButtonDown.pressing());
  // Stop the motor
  spooderman.stop();
}

void check_color(){
  
  if(Optical2.color() == red){

  Brain.Screen.print("Red object: ");
  Brain.Screen.newLine();
  }
  if(Optical2.color() == blue){

  Brain.Screen.print("blue object: ");
  Brain.Screen.newLine();
  }
  if(Optical2.color() == green){

  Brain.Screen.print("Green object: ");
  Brain.Screen.newLine();
  }

  else
    Brain.Screen.print("No color detected");
    Brain.Screen.newLine();
     
}

// A global instance of competition
competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
   // Initialize the Contoller Events
  Controller1.ButtonL1.pressed(ControllerL1Pressed);
  Controller1.ButtonL2.pressed(ControllerL2Pressed);
  Controller1.ButtonR1.pressed(ControllerR1Pressed);
  Controller1.ButtonR2.pressed(ControllerR2Pressed);
  Controller1.ButtonX.pressed(ControllerXPressed);
  Controller1.ButtonA.pressed(ControllerAPressed);
  Controller1.ButtonY.pressed(ControllerYPressed);
  Controller1.ButtonUp.pressed(ControllerUpPressed);
  Controller1.ButtonDown.pressed(ControllerDownPressed);

  Brain.Screen.clearScreen();
  Brain.Screen.print("pre auton code");
  wait(1, seconds);
  Intake1.setStopping(hold);
  Intake2.setStopping(hold);
  spooderman.setStopping(hold);
  Intake1.setVelocity(100,percent);
  Intake2.setVelocity(100,percent);
  //flywheel_group.setVelocity(75,percent);
  Roller.setStopping(hold);
  Roller.setVelocity(70,percent);
  flywheel_group.setVelocity(65, percent);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.print("autonomous code");
  Brain.Screen.setCursor(4, 2);
  // place automonous code here
  //front_left.setReversed(true);
  Brain.Screen.print("Setting params");
  rear_left.setVelocity(50, percent);
  front_right.setVelocity(50, percent);
  rear_right.setVelocity(50, percent);
  front_left.setVelocity(50, percent);


  Brain.Screen.print("Striffing right");
  Brain.Screen.newLine();
 front_left.spinFor(forward, 2.5, turns, false);
 front_left.setBrake(brake);
 rear_left.spinFor(reverse, 2.5, turns, false);
 rear_left.setBrake(brake);
 front_right.spinFor(reverse, 2.5, turns, false);
 front_right.setBrake(brake);
 rear_right.spinFor(forward, 2.5, turns, true);
 rear_right.setBrake(brake);

wait(500, msec);

Brain.Screen.print("Moving backwards");
  Brain.Screen.newLine();

front_right.spin(reverse);
front_left.spin(reverse);
rear_right.spin(reverse);
rear_left.spin(reverse);

//waitUntil(Bumper_A.pressing());

wait(500, msec);

front_right.stop();
front_left.stop();
rear_left.stop();
rear_right.stop();

wait(500, msec);

Brain.Screen.print("Searching Alliance Color");
Brain.Screen.newLine();
// Change color at the beginning of each match REMINDER
color alliance_color=red;

check_color();
//if(Optical2.isNearObject()){
  Brain.Screen.print("Object detected");
  Brain.Screen.newLine();

  // Speed for wheels in second if statement
  rear_left.setVelocity(30, percent);
  front_right.setVelocity(30, percent);
  rear_right.setVelocity(30, percent);
  front_left.setVelocity(30, percent);

  front_right.spin(reverse);
  front_left.spin(reverse);
  rear_right.spin(reverse);
  rear_left.spin(reverse);

    wait(20, msec);

  Brain.Screen.print("Spinwheel turning");
  Controller1.Screen.print("Spinwheel Turning");
  Brain.Screen.newLine();

    Intake2.spinFor(forward, 1, turns);
    Intake1.spinFor(reverse, 1, turns);

    //if(Optical2.color() == alliance_color){
      //check_color();
      Intake2.stop();
      Intake1.stop();

  Brain.Screen.print("Auton Stop");
  Controller1.Screen.print("Auton Stop");
  Brain.Screen.newLine();

      front_right.stop();
      front_left.stop();
      rear_left.stop();
      rear_right.stop();
    //}
  //}
//}

Brain.Screen.print("Roller contact");
  Brain.Screen.newLine();
  

  /*
    if (Optical2.isNearObject()) {
      Brain.Screen.print("Object Detected");
      Brain.Screen.newLine();
      
      Brain.Screen.print("Brightness: ");
      Brain.Screen.print("%.2f", Optical2.brightness());
      Brain.Screen.newLine();

      Brain.Screen.print("Hue: ");
      Brain.Screen.print("%.2f", Optical2.hue());
      Brain.Screen.newLine();

      Brain.Screen.print("Detects a red object?: ");
      Brain.Screen.print("%s", Optical2.color() == red ? "TRUE" : "FALSE");
      Brain.Screen.newLine();

      Brain.Screen.print("Detects a green object?: ");
      Brain.Screen.print("%s", Optical2.color() == green ? "TRUE" : "FALSE");
      Brain.Screen.newLine();

      Brain.Screen.print("Detects a blue object?: ");
      Brain.Screen.print("%s", Optical2.color() == blue ? "TRUE" : "FALSE");
      Brain.Screen.newLine();
    } else {
      Brain.Screen.print("No Object Detected");
    }*/

    // A brief delay to allow text to be printed without distortion or tearing
    wait(0.2, seconds);
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    wait(20, msec);
    //task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
    //rc_auto_loop_function_Controller1();
    int X2 = 0, Y1 = 0, X1 = 0, threshold = 20;

    

    int forward = Controller1.Axis3.position(vex::percent);
    int sideways = Controller1.Axis4.position(vex::percent);
    int turn = Controller1.Axis1.position(vex::percent);

/*
    motor[frontLeft] = abs(front_left)>
    deadzone 10 front_left : O;
    motor[rearLeft] = abs(rear_left)>
    deadzone 10 rear_left : O;
    motor[frontRight] = abs(front_right)>
    deadzone 10 front_right : O;
    motor[rearRight] = abs(rear_right)>
    deadzone 10 rear_right : O;
*/

    if(abs(forward) > threshold)
      Y1 = forward;
    else
      Y1 = 0;
      //Create "deadzone" for X1/Ch4
    if(abs(sideways) > threshold)
      X1 = sideways;
    else
      X1 = 0;
    //Create "deadzone" for X2/Ch1
    if(abs(turn) > threshold)
      X2 = turn;
    else
      X2 = 0;


    front_right.spin(vex::forward, Y1 - X1 - X2, vex::percent);
    front_left.spin(vex::forward,  Y1 + X1 + X2, vex::percent);
    rear_right.spin(vex::forward,  Y1 + X1 - X2, vex::percent);
    rear_left.spin(vex::forward,   Y1 - X1 + X2, vex::percent);
    
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
