//
//  ResetButtonDecorator.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/11/2017.
//

#include "ResetButtonDecorator.hpp"
#include "GUIStyle.hpp"
#include "Primitives.hpp"
#include "Slider.hpp"

void ResetButtonDecorator::draw(NVGcontext* vg)
{
    Decorator::draw(vg);
    
    ofRectangle theRect;
    Boolean isHovered;
    ofColor backgroundColor;
    
    theRect = resetButton.rect;
    if (parent != NULL) {
        theRect.x = theRect.x + parent->rect.x;
        theRect.y = theRect.y + parent->rect.y;
    }
    backgroundColor = Button::getBackgroundColor(resetButton.hover, resetButton.pushed);
    drawButton(vg, resetButton.caption, theRect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
}

void ResetButtonDecorator::set(json config) {
    Decorator::set(config);
    
    resetButton.caption = "X";
    resetButton.rect.width = resetButton.rect.height = config["height"];
    resetButton.rect.y = config["y"].get<float>();
    resetButton.rect.x = config["x"].get<float>() + config["width"].get<float>() - resetButton.rect.width;
    
    config["width"] = config["width"].get<float>() - resetButton.rect.width - (GUI_BORDER / 2.0);
    getElement()->set(config);
}

void ResetButtonDecorator::update() {
    Decorator::update();
    
    Boolean previousPressed = resetButton.pressed;
    Boolean previousHover = resetButton.hover;
    ofRectangle visibleRect;
  
    visibleRect = resetButton.rect;
    if (parent != NULL) {
        visibleRect.x = visibleRect.x + parent->rect.x;
        visibleRect.y = visibleRect.y + parent->rect.y;
    }
    
    resetButton.hover = visibleRect.inside(ofGetMouseX(), ofGetMouseY());
    if (resetButton.hover) {
        resetButton.pressed = pressed;
        
        if (resetButton.pressed == true && previousPressed != resetButton.pressed && previousHover == true) resetButton.pushed = true;
        
        //cout << ( (resetButton.pushed)? "pushed":"not pussed") << endl;
        if (resetButton.pushed) {
            Decorator::getElement()->setDefaultValue();
        }
    }
    else {
        resetButton.pressed = false;
        resetButton.pushed = false;
    }
}


void ResetButtonDecorator::setParent(Element *_parent) {
    Decorator::setParent(_parent);
}
