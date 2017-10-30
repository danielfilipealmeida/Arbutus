//
//  Primitives.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#ifndef Primitives_hpp
#define Primitives_hpp

#include <stdio.h>
#include "ofMain.h"
#include "nanovg.h"

/*!
 \brief Prints the information of an openFrameworks color
 */
void print(ofColor color);

/*!
 \brief Convert ofColor (openFrameworks) to NVGColor (nano)
 */
NVGcolor ofColor2NVGColor(ofColor color, unsigned char alpha = 255);

/*!
 Draws a button
 */
void drawButton(NVGcontext* vg, int preicon, string text, ofRectangle rect, NVGcolor backgroundColor, NVGcolor textColor);

/*!
 Draws a slider
 */
void drawSlider(NVGcontext* vg, float pos, string text, ofRectangle rect, NVGcolor backgroundColor, NVGcolor textColor, Boolean vertical = false);


/*!
 Draws a rectangle with rounded corners
 */
void drawBox(NVGcontext* vg, ofRectangle rect, NVGcolor col, float cornerRadius);

/*!
 Makes the rect smaller by the given amount of pixels
 */
void shrinkRect(ofRectangle &rect, float pixels);

void printCenteredText(NVGcontext* vg, int preicon, string text, ofRectangle rect, NVGcolor textColor);

void printText(NVGcontext* vg, string text, float x, float y, NVGcolor textColor);

void drawFilledRect(NVGcontext* vg, ofRectangle rect, NVGcolor col);


#endif /* Primitives_hpp */
