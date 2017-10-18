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
 ...
 */
void print(ofColor color);

/*!
 Convert ofColor to NVGColor

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

#endif /* Primitives_hpp */
