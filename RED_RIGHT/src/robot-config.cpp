#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Intake1 = motor(PORT1, ratio36_1, true);
motor Intake2 = motor(PORT2, ratio36_1, true);
optical Optical2 = optical(PORT8);
motor Roller = motor(PORT10, ratio18_1, true);

motor lancher = motor(PORT9, ratio18_1, true);

motor flywheel_groupMotorA = motor(PORT11, ratio6_1, true);
motor flywheel_groupMotorB = motor(PORT15, ratio6_1, false);
motor_group flywheel_group = motor_group(flywheel_groupMotorA, flywheel_groupMotorB);

motor front_left = motor(PORT19, ratio18_1, false);//leftA
motor rear_left = motor(PORT20, ratio18_1, false);///leftB
motor front_right = motor(PORT18, ratio18_1, true);//rightA
motor rear_right = motor(PORT17, ratio18_1, true);

motor spooderman = motor(PORT16, ratio18_1, true);

bumper Bumper_A = bumper(Brain.ThreeWirePort.A);

digital_out DigitalOutH = digital_out(Brain.ThreeWirePort.H);
digital_out DigitalOutG = digital_out(Brain.ThreeWirePort.G);

controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}