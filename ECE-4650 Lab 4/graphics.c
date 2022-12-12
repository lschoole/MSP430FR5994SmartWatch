/*
 * graphics.c
 *
 *  Created on: Apr 3, 2021
 *      Author: Luke Schooley
 */
#include "graphics.h"
// ---------------------------------------------------------------------------------------------------
void clear(Graphics_Context * context) {
    // Set our default background and foreground colors
    Graphics_setBackgroundColor(context, GRAPHICS_COLOR_BLACK);
    Graphics_setForegroundColor(context, GRAPHICS_COLOR_WHITE);
    // Clear the screen
    Graphics_clearDisplay(context);
}
// ---------------------------------------------------------------------------------------------------
void Initialize_Graphics(Graphics_Context * context) {
    // Set our screen orientation
    Crystalfontz128x128_SetOrientation(0);
    // Initialize our graphics context
    Graphics_initContext(context, &g_sCrystalfontz128x128);
    // Set our default background and foreground colors
    Graphics_setBackgroundColor(context, GRAPHICS_COLOR_BLACK);
    Graphics_setForegroundColor(context, GRAPHICS_COLOR_WHITE);
    // Establish our default font
    GrContextFontSet(context, &g_sFontCm16);
    // Clear the screen
    Graphics_clearDisplay(context);
    // Set the display's backlight to high -- this breaks buzzer lol
    //P3DIR |= BIT6;
    //P3OUT |= BIT6;
}
// ---------------------------------------------------------------------------------------------------
void write(Graphics_Context *context, char message[], int x, int y) {
    GrStringDraw(context, message, -1, x, y, 0);
}
// ---------------------------------------------------------------------------------------------------
void writeNum(Graphics_Context *context, int num, int x, int y) {
    char str[5];
    sprintf(str,"%d",num);
    write(context,str,x,y);
}
// ---------------------------------------------------------------------------------------------------
void drawCenteredLine(Graphics_Context *context, int x, int y) {
    Graphics_drawLine(context, 64, 64, x, y);
}
// ---------------------------------------------------------------------------------------------------
void drawPause(Graphics_Context *context) {
    Graphics_setForegroundColor(context, GRAPHICS_COLOR_WHITE);
    write(context,"Set Time",45,2);
    write(context,"Switch Display",20,20);
    write(context,"Kids",50,40);
    write(context,"Time to Pretend",5,60);
    write(context,"Little Dark Age",5,80);
    write(context,"Synthesizer",28,100);
}
// ---------------------------------------------------------------------------------------------------
void drawBMP(Graphics_Context *context, const Graphics_Image *pBitmap, int16_t x, int16_t y) {
    Graphics_drawImage(context, pBitmap, x, y);
}
