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
    
    ofRectangle theRect, visibleRect;
    Boolean isHovered;
    ofColor backgroundColor;
    
    visibleRect = resetButton.rect;
    isHovered =  visibleRect.inside(ofGetMouseX(), ofGetMouseY());
    backgroundColor = Button::getBackgroundColor(isHovered, pressed);
    drawButton(vg, resetButton.caption, resetButton.rect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
    
}

void ResetButtonDecorator::set(json config) {
    Decorator::set(config);
    resetButton.rect.width = resetButton.rect.height = config["height"];
    resetButton.rect.y = config["y"];
    resetButton.rect.x = config["x"].get<float>() + config["width"].get<float>() - resetButton.rect.width;
    config["width"] = config["width"].get<float>() - resetButton.rect.width - (GUI_BORDER / 2.0);
    
    resetButton.caption = "X";
    
    getElement()->set(config);
}

void ResetButtonDecorator::update() {
    Decorator::update();
    
    Boolean previousPressed = resetButton.pressed;
    Boolean previousHover = resetButton.hover;
    ofRectangle visibleRect;
  
    resetButton.hover = resetButton.rect.inside(ofGetMouseX(), ofGetMouseY());
    if (resetButton.hover) {
        resetButton.pressed = pressed;
        
        if (resetButton.pressed == true && previousPressed != resetButton.pressed && previousHover == true) resetButton.pushed = true;
        
        if (resetButton.pushed) {
            Decorator::getElement()->setDefaultValue();
        }
    }
    else {
        resetButton.pressed = false;
        resetButton.pushed = false;
    }
   
}
