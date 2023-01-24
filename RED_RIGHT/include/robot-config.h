using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Intake1;
extern motor Intake2;
extern motor front_right;
extern motor rear_right;
extern motor front_left;
extern motor rear_left;
extern motor Roller;
extern motor flywheel_groupMotorA;
extern motor flywheel_groupMotorB;
extern motor_group flywheel_group;
extern motor spooderman;
extern motor lancher;
extern bumper Bumper_A;
extern digital_out DigitalOutH;
extern digital_out DigitalOutG;
extern optical Optical2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );