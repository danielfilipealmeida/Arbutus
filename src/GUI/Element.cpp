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



void Element::set(json config) {
    if (!config.is_object()) throw("not a json object");
    if (!config["x"].is_number()) throw("x not defined");
    if (!config["y"].is_number()) throw("x not defined");
    if (!config["width"].is_number()) throw("x not defined");
    if (!config["height"].is_number()) throw("x not defined");
    
    rect.set(config["x"].get<unsigned int>(),
             config["y"].get<unsigned int>(),
             config["width"].get<unsigned int>(),
             config["height"].get<unsigned int>());
}
