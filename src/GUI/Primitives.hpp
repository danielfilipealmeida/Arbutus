//
//  Primitives.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#ifndef Primitives_hpp
#define Primitives_hpp

#include "nanovg.h"

void drawButton(NVGcontext* vg, int preicon, const char* text, float x, float y, float w, float h, NVGcolor col);
void drawSlider(NVGcontext* vg, float pos, float x, float y, float w, float h);



#include <stdio.h>

#endif /* Primitives_hpp */
