/******************************************************************
// Read the header file to see more information on how to use this
//
******************************************************************/

//  ________ ________ ________
//  | red  | | red  | | red  |
//  | left | | idle | | right|
//  ________ ________ ________
//  | blue | | blue | | blue |
//  | left | | idle | | right|


// Once the alliance color has been selected, the controller will rumbke to provide feedback
// Following are the patterns based on what are selected:
// . = short pulse
// - = long pulse
// .... = idle state
// ---- = blue
// -... = red

#include "vex.h"

/*
int whitespace;
int height = 230;
int width = 125;
int xPos = 5;
int yPos = 5;
int xMin = xPos - (width/2);
int yMin;
int xMax = xPos + (width/2);
int yMax;
color alliance_color;
char alliance_color_char;
*/


void color_to_string(color c);

void alliance_selector_2();

//
int alliance_selector_4();


// Creates the shapes on the Brain screen
// Composed of 1 red, 1 blue and 1 idle
void Screen_draw_2(void);

// Creates the shapes on the Brain screen
// Composed of 2 red, 2 blue and 1 idle
void Screen_draw_4(void);

