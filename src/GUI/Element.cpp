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
    entered = FALSE;
    exited = FALSE;
}


Element::~Element()
{
    
}


void Element::update()
{
    Boolean previousHover = hover;
    
    if (!rect.inside(ofGetMouseX(), ofGetMouseY())) {
        hover = FALSE;
        pressed = FALSE;
    }
    else {
        hover = TRUE;
        pressed = (ofGetMousePressed() > 0);
    }
    
    if (hover) {
        entered = (!previousHover) ? TRUE : FALSE;
    }
    else {
        exited = (previousHover) ? TRUE : FALSE;
    }
}

void Element::draw(NVGcontext* vg) {
    
}
