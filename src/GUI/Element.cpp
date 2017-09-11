//
//  Element.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "Element.hpp"


Element::Element()
{
    hover = FALSE;
    pressed = FALSE;
}


Element::~Element()
{
    
}


void Element::update()
{
    if (rect.inside(ofGetMouseX(), ofGetMouseY())) {
        hover = FALSE;
        pressed = FALSE;
    }
    else {
        hover = TRUE;
        if (ofGetMousePressed() > 0) pressed = true;
    }
}

void Element::draw(NVGcontext* vg) {
    
}
