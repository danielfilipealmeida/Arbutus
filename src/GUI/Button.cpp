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
    pushed = false;
    caption = "";
}


Button::~Button()
{
    
}

void Button::update() {
    Boolean previousPressed = pressed;
    
    Element::update();

    if (pressed == FALSE &&
        previousPressed != pressed
        )
    {
        onClick(this);
    }
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
    drawButton(vg, 1, caption, getRect(), ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));

    Element::finishDraw(vg);
}



void Button::set(json config) {
    Element::set(config);
    if (config["caption"].is_string()) caption = config["caption"].get<string>();
}

void Button::setOnClick(std::function<void(Button *button)> _onClick) {
    onClick = _onClick;
}



