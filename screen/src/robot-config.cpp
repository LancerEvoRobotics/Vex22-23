#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
//motor Shooter = motor(PORT8, ratio18_1, true);

motor front_right = motor(PORT6, ratio18_1, false);
motor front_left  = motor(PORT7, ratio18_1, false);
motor rear_right  = motor(PORT8, ratio18_1, false);
motor rear_left  = motor(PORT9, ratio18_1, false);

// Sensors
distance Distance1 = distance(PORT3);
optical Optical2 = optical(PORT2);

motor MotorGroup_BeltMotorA = motor(PORT21, ratio18_1, false);
motor MotorGroup_BeltMotorB = motor(PORT20, ratio18_1, false);
motor_group MotorGroup_Belt = motor_group(MotorGroup_BeltMotorA, MotorGroup_BeltMotorB);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1RightShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);

  //CHeck that the distance sensor is functioning
  Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Found Object\?:");
    Brain.Screen.print("%s", Distance1.isObjectDetected() ? "TRUE" : "FALSE");
    Brain.Screen.newLine();
    if (Distance1.isObjectDetected()) {
      if (Distance1.objectSize() == sizeType::large) {
        Brain.Screen.print("Object: Large");
        Brain.Screen.newLine();
      }
      if (Distance1.objectSize() == sizeType::medium) {
        Brain.Screen.print("Object: Medium");
        Brain.Screen.newLine();
      }
      if (Distance1.objectSize() == sizeType::small) {
        Brain.Screen.print("Object: Small");
        Brain.Screen.newLine();
      }
    }
    else {
      Brain.Screen.print("No object");
      Brain.Screen.newLine();
    }
    //Brain_precision = 2;
    Brain.Screen.print("Distance - Inches:");
    Brain.Screen.print(static_cast<float>(Distance1.objectDistance(inches)));
    Brain.Screen.newLine();
    //Brain.Screen.print("Distance - MM:");
    //Brain.Screen.print(static_cast<float>(Distance1.objectDistance(mm)));
    //Brain.Screen.newLine();
    Brain.Screen.print("Object velocity - M/S:");
    Brain.Screen.print( static_cast<float>(Distance1.objectVelocity()));
    Brain.Screen.newLine();
    // A brief delay to allow text to be printed without distortion or tearing
    wait(0.05, seconds);
  wait(5, msec);
}