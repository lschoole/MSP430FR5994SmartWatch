/*
 * graphics.h
 *
 *  Created on: Apr 3, 2022
 *      Author: Luke Schooley
 */
#ifndef GRAPHICS_H_
#define GRAPHICS_H_
// ---------------------------------------------------------------------------------------------------
#include "Grlib/grlib/grlib.h"      // Graphics Library Import
#include "LcdDriver/lcd_driver.h"
#include <msp430fr5994.h>
#include <stdio.h>
// ---------------------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C"
{
#endif
// ---------------------------------------------------------------------------------------------------
/*
 * clear the screen
 */
void clear(Graphics_Context * context);
/*
 * Initialize the default settings for our graphics context and screen
 */
void Initialize_Graphics(Graphics_Context * context);
/*
 * display a string/character array on screen
 */
void write(Graphics_Context *context, char message[], int x, int y);
/*
 * display a number on screen
 */
void writeNum(Graphics_Context *context, int num, int x, int y);
/*
 * draw a sized line from center of screen to x and y on screen
 */
void drawCenteredLine(Graphics_Context *context, int x, int y);
/*
 * draw the pause menu
 */
void drawPause(Graphics_Context *context);
/*
 * draw a bit map picture - upper left corner is (x,y)
 */
void drawBMP(Graphics_Context *context, const Graphics_Image *pBitmap, int16_t x, int16_t y);
// ---------------------------------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif
// ---------------------------------------------------------------------------------------------------
#endif /* GRAPHICS_H_ */
