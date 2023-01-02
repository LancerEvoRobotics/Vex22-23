/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Tank Drive                                                */
/*    This sample allows you to control the V5 Clawbot using the both         */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Shooter              motor         8               
// MotorGroupLeft       motor_group   6, 13           
// MotorGroupRight      motor_group   7, 14           
// MotorGroup_Belt      motor_group   21, 20          
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
//#include "auton.h"
#include "screen_print.h"

using namespace vex;

// A global instance of competition
competition Competition;

//variable to hold the selected auton

//
enum auton {
  red_left = 0,
  red_right,
  blue_left,
  blue_right,
  red_idle,
  blue_idle

} selected_auton;

int selected_auto;



void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Screen_draw_2();
  Screen_draw_4();

  //Brain.Screen.pressed(alliance_selector_2);
  
  selected_auto = alliance_selector_4();

  //Brain.Screen.pressed(alliance_selector_4);
  //wait(10,msec);
  // Possibly move this into a 
  //alliance_selector();
  
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
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  auton(selected_auto);
  //alliance_selector();
 // Brain.Screen.clearScreen();
 // if(alliance_selector() == vex::color::red)
 //   Brain.Screen.printAt(20, 20, "Red from auton");
 // if(alliance_selector() == vex::color::blue)
 //   Brain.Screen.printAt(20, 20, "blue");
  
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
  //Brain.Screen.clearScreen();
  // User control code here, inside the loop
  while (1) {
    

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    int deadband = 10;
   
    int forward = Controller1.Axis3.position(vex::percent);
    int sideways = Controller1.Axis4.position(vex::percent);
    int turn = Controller1.Axis1.position(vex::percent);

    front_right.spin(vex::forward, forward - sideways + turn, vex::percent);
    front_left.spin(vex::forward,  forward + sideways - turn, vex::percent);
    rear_right.spin(vex::forward,  forward + sideways + turn, vex::percent);
    rear_left.spin(vex::forward,   forward - sideways - turn, vex::percent);

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


