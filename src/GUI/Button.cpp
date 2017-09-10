//
//  Button.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "Button.hpp"
#include "Primitives.hpp"

Button::Button()
{
    
}


Button::~Button()
{
    
}


void Button::draw(NVGcontext* vg)
{
    drawButton(vg, 1, caption.c_str(), rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight(), nvgRGBA(128,128,0,255));
    
}

void Button::set(json buttonConfig) {
    if (!buttonConfig.is_object()) throw("not a json object");
    
    rect.set(buttonConfig["x"].get<unsigned int>(),
             buttonConfig["y"].get<unsigned int>(),
             buttonConfig["width"].get<unsigned int>(),
             buttonConfig["height"].get<unsigned int>());
    caption = buttonConfig["caption"].get<string>();
}
