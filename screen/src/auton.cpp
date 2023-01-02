

//This function will contain a case statement to run one of the five possible events:
//red_left, red_right
//blue_left, blue_right
//idle

/*
enum auton {
  red_left = 0,
  red_right,
  blue_left,
  blue_right,
  red_idle,
  blue_idle
} 
*/


#include "vex.h"
#include "auton.h"

void auton_selector(color team_color, char side){

  Brain.Screen.setCursor(10,2);
  Brain.Screen.clearLine();


    switch(team_color){
      case 0:
        Brain.Screen.print("Running first aution code");
        break;
      
      case 1:
      Brain.Screen.print("Running first aution code");
    }

}

void test_optical(){
  Brain.Screen.setCursor(3,1);
  Brain.Screen.clearLine();
  Brain.Screen.print("Current state: Pressed ");

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
    }
}
