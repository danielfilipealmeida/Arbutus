//
//  Button.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "Button.hpp"
#include "Primitives.hpp"
#include "GUIStyle.hpp"

Button::Button()
{
    
}


Button::~Button()
{
    
}

void Button::update() {
    Element::update();
}

void Button::draw(NVGcontext* vg)
{
    ofColor backgroundColor;
    Element::draw(vg);
    if (hover == FALSE) {
        backgroundColor = GUIStyle::getInstance().getBackgroundColor();
    }
    else {
        if (pressed == TRUE) {
            backgroundColor = GUIStyle::getInstance().getDarkColor();

        }
        else  {
            backgroundColor = GUIStyle::getInstance().getLightColor();

        }
        
    }
    print(backgroundColor);
    drawButton(vg, 1, caption, rect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
}



void Button::set(json config) {
    if (!config.is_object()) throw("not a json object");
    
    rect.set(config["x"].get<unsigned int>(),
             config["y"].get<unsigned int>(),
             config["width"].get<unsigned int>(),
             config["height"].get<unsigned int>());
    caption = config["caption"].get<string>();
}
