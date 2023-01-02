/******************************************************************
// Read the header file to see more information on how to use this
//
******************************************************************/

#include "vex.h"
#include "screen_print.h"

int whitespace = 10;
int height = 230;
int width = 150;
int xPos = 5;
int yPos = 5;
int xMin = xPos - (width/2);
int yMin;
int xMax = xPos + (width/2);
int yMax;
color alliance_color;
char alliance_color_char;
char alliance_side;
int auton_bin = 111;

// 3 bit state
// red = 0
// blue = 1
// left = 0
// right = 1
// idle? = 0 / 1

// idle? | color | side | 
//   0       0      0  -> no, blue, left
//   0       0      1  -> no,  blue, right
//   0       1      0  -> no, red, left
//   0       1      1  -> no,  red, right
//   1      X/0     0  -> yes, X, red
//   1      X/0     1  -> yes, X, blue
//   1       1      1  -> undeclared


void color_to_string(color c){

  switch(c)
    red:
      Brain.Screen.print( "red");
      
    blue:
      Brain.Screen.print( "blue");
  return;

}

void alliance_selector_2(){
   
  if(Brain.Screen.xPosition()<= width)
  {
    alliance_color = alliance_color_char =  red;
    Controller1.rumble("-...");
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(0, 0, 480, 240);
    Brain.Screen.setCursor(5, 10);
    Brain.Screen.print("Alliance color selected: red" );
  
  }
  //if idle button pressed
  else if (Brain.Screen.xPosition()>= width && Brain.Screen.xPosition()<= (width*2) ) {
    alliance_color = purple;
    Controller1.rumble("....");
    Brain.Screen.setFillColor(purple);
    Brain.Screen.drawRectangle(0, 0, 480, 240);
    Brain.Screen.setCursor(5, 10);
    Brain.Screen.print("Alliance color selected: none" );
  }
  else if (Brain.Screen.xPosition()>= (width*2) && Brain.Screen.xPosition()<= (width*3)) {
    alliance_color = blue;
    Controller1.rumble("----");
    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(0, 0, 480, 240);
    Brain.Screen.setCursor(5, 10);
    Brain.Screen.print("Alliance color selected: blue" );
  }//nothing is selected
  else{
    alliance_color = purple;
    Brain.Screen.setFillColor(purple);
    Brain.Screen.drawRectangle(0, 0, 480, 240);
    Brain.Screen.setCursor(5, 10);
    Brain.Screen.print("Alliance color selected: purp" );
  }
}

int alliance_selector_4(){
   //Three nested ifs
   
   Brain.Screen.setCursor(6, 8);

  while(true){
  if(Brain.Screen.pressing()){
    if(Brain.Screen.xPosition()<= width)
    {
      if(Brain.Screen.yPosition()<= height/2){
        // red left
        alliance_color = alliance_color_char = red;
        alliance_side = 'l';
        auton_bin = 010;
        Controller1.rumble("-");
        //Brain.Screen.setFillColor(red);
        //Brain.Screen.drawRectangle(0, 0, 480, 240);
        //Brain.Screen.print("Alliance color selected: red Left" );
      }
      else{
        // blue left
        alliance_color = alliance_color_char =  blue;
        alliance_side = 'l';
        auton_bin = 000;
        Controller1.rumble("-");
        //Brain.Screen.setFillColor(blue);
        //Brain.Screen.drawRectangle(0, 0, 480, 240);
        //Brain.Screen.print("Alliance color selected: blue left" );
      }
    
    }

      // idles
    else if(Brain.Screen.xPosition()>= (width + whitespace)  && Brain.Screen.xPosition()<= ((width*2) +whitespace))
    {
      // red idle
      if(Brain.Screen.yPosition()<= height/2){
        alliance_color = alliance_color_char =  red;
        alliance_side = 'i';
        auton_bin = 100;
        Controller1.rumble("..");
        //Brain.Screen.setFillColor(red);
        //Brain.Screen.drawRectangle(0, 0, 480, 240);
        //Brain.Screen.print("Alliance color selected: red idle" );
      }
      else{
        // blue idle
        alliance_color = alliance_color_char =  blue;
        alliance_side = 'i';
        auton_bin = 101;
        Controller1.rumble("..");
        //Brain.Screen.setFillColor(blue);
        //Brain.Screen.drawRectangle(0, 0, 480, 240);
        //Brain.Screen.print("Alliance color selected: blue idle" );
      }
    }

    else if(Brain.Screen.xPosition() >= ((width + whitespace)*2))
    {
      // red right
      if(Brain.Screen.yPosition() <= height / 2){
        alliance_color = alliance_color_char =  red;
        alliance_side = 'r';
        auton_bin = 001;
        Controller1.rumble("--");
        //Brain.Screen.setFillColor(red);
        //Brain.Screen.drawRectangle(0, 0, 480, 240);
        //Brain.Screen.print("Alliance color selected: red right" );
      }
      else{
        // blue right
        alliance_color = alliance_color_char =  blue;
        alliance_side = 'r';
         auton_bin = 011;
        Controller1.rumble("--");
        //Brain.Screen.setFillColor(blue);
        //Brain.Screen.drawRectangle(0, 0, 480, 240);
        //Brain.Screen.print("Alliance color selected: blue right" );
      }
    
    }
    // nothing is selected
    else{
      //alliance_color = NULL;
      //alliance_color = alliance_color_char =  blue;
      alliance_side = 'i';
      auton_bin = 111;
      Brain.Screen.setFillColor(purple);
      //Brain.Screen.drawRectangle(0, 0, 480, 240);
      //Brain.Screen.print("Alliance color selected: null" );
    }

  }
  // Button has been selected
  // Make screen reflect the chosen auton
  Brain.Screen.setFillColor(alliance_color);
  Brain.Screen.drawRectangle(0, 0, 480, 240);
  Brain.Screen.print("Alliance color selected: %c  %c", alliance_color_char, alliance_side);
  
  
  wait(10,msec);
  }
  return auton_bin;

}

void Screen_draw_2(void){
  //Globals here
  Brain.Screen.setPenWidth(3);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFont(propXL);
  //Brain.Screen.setOutline
  //Screen dimensions: 480 W:240 H
  
  //Red Alliance
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(xPos, yPos, width, height, red);
  //Brain.Screen.printAt( x,  y, "RED");

  //Idle state
  Brain.Screen.setFillColor(purple);
  Brain.Screen.drawRectangle(xPos+width + whitespace , yPos  + height/4, width, height/2, purple);

  //Blue Alliance
  Brain.Screen.setFillColor(purple);
  Brain.Screen.drawRectangle(xPos+(width*2) + (whitespace*2) , yPos, width, height/2, blue);
  //Brain.Screen.printAt( x,  y, "Blue");
  
  //Brain.Screen.pressed(alliance_selector);

  //waitUntil(Brain.Screen.pressing());
  //Brain.Screen.pressed(alliance_selector);

}


void Screen_draw_4(void){
  //Globals here
  Brain.Screen.setPenWidth(3);
  Brain.Screen.setPenColor(white);
  //Brain.Screen.setOutline
  //Screen dimensions: 480 W:240 H
  
  //Red Alliance Left
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(0, 0, width, height/2, red);
  //Brain.Screen.printAt( x,  y, "RED");

   //Blue Alliance Left
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(0 , height/2, width, height/2, blue);
  //Brain.Screen.printAt( x,  y, "Blue");

  //Idle state Red
  Brain.Screen.setFillColor(purple);
  Brain.Screen.drawRectangle(width + whitespace , 0, width, height/2, purple);

//Idle state Blue
  Brain.Screen.setFillColor(purple);
  Brain.Screen.drawRectangle(width + whitespace , height/2, width, height/2, purple);


  //Red Alliance Right
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle((width + whitespace)*2, 0, width, height/2, red);
  //Brain.Screen.printAt( x,  y, "RED");


  //Blue Alliance Right
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle((width + whitespace)*2 , height/2, width, height/2, blue);
  //Brain.Screen.printAt( x,  y, "Blue");
  
}

