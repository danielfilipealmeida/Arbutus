//
//  ToggleButton.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "ToggleButton.hpp"
#include "Primitives.hpp"
#include "GUIStyle.hpp"

void ToggleButton::update() {
    Boolean previousPressed = pressed;
    
    Element::update();
    
    if (pressed == FALSE && previousPressed != pressed) {
        pushed = !pushed;
        onClick(this);
    }
}

void ToggleButton::draw(NVGcontext* vg)
{
    ofColor backgroundColor;
    
    Element::draw(vg);
    if (hover == FALSE) {
        backgroundColor = pushed ? GUIStyle::getInstance().getLightColor() : GUIStyle::getInstance().getBackgroundColor();
    }
    else {
        //backgroundColor = pressed ? GUIStyle::getInstance().getDarkColor() : GUIStyle::getInstance().getLightColor();
        if (pressed) {
            backgroundColor = pushed ? GUIStyle::getInstance().getDarkColor(): GUIStyle::getInstance().getDarkColor() * 1.5;
        }
        else {
            backgroundColor =  pushed ? GUIStyle::getInstance().getLightColor() * 1.5 : GUIStyle::getInstance().getLightColor();
        }
    }
    drawButton(vg, icon, caption, getRect(), ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
    
    Element::finishDraw(vg);
}

void ToggleButton::setOnClick(std::function<void(ToggleButton *toggleButton)> _onClick) {
    onClick = _onClick;
}

Boolean ToggleButton::isPushed() {
    return pushed;
}

void ToggleButton::setPushed(Boolean _pushed) {
    pushed = _pushed;
}
