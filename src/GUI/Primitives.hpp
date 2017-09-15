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

void print(ofColor color);
NVGcolor ofColor2NVGColor(ofColor color, unsigned char alpha = 255);
void drawButton(NVGcontext* vg, int preicon, string text, ofRectangle rect, NVGcolor backgroundColor, NVGcolor textColor);
void drawSlider(NVGcontext* vg, float pos, string text, ofRectangle rect, NVGcolor backgroundColor, NVGcolor textColor);



#include <stdio.h>

#endif /* Primitives_hpp */
