using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Shooter;
extern motor front_left;
extern motor front_right;
extern motor rear_left;
extern motor rear_right;

// Sensors
extern distance Distance1;
extern optical Optical2;




/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );