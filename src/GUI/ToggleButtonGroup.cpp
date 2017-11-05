//
//  ToggleButtonGroup.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "ToggleButtonGroup.hpp"
#include "GUI.hpp"
#include "GUIStyle.hpp"
#include "Primitives.hpp"


void ToggleButtonGroup::draw(NVGcontext* vg)
{
    Element::draw(vg);
    
    for (auto button:buttons) {
        ofRectangle theRect, visibleRect;
        Boolean isHovered;
        ofColor backgroundColor;
        
        theRect = button.rect;
        theRect.x = theRect.x + rect.x;
        theRect.y = theRect.y + rect.y;
        
        visibleRect = getVisibleRectForButton(button);
        isHovered =  visibleRect.inside(ofGetMouseX(), ofGetMouseY());
        backgroundColor = ToggleButton::getBackgroundColor(isHovered, button.pressed, button.pushed );
        drawButton(vg, 0, button.caption, theRect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
    }
    
    Element::finishDraw(vg);
}

void ToggleButtonGroup::update()
{
    
    Element::update();
    
    for (auto &button:buttons) {
        Boolean previousPressed = button.pressed;
        ofRectangle visibleRect;
        
        visibleRect = getVisibleRectForButton(button);
        if (!visibleRect.inside(ofGetMouseX(), ofGetMouseY())) continue;
     
        if (pressed) {
            button.pressed = pressed;
            
            if (button.pressed != previousPressed) {
                button.pushed = ! button.pushed;
            }
            
            selectedButtonData = button;
            for (auto &button2:buttons) {
                if (&button2 != &button) {
                    button2.pressed = false;
                    button2.pushed = false;
                }
            }
            if (onClick != NULL) onClick(this);
            //break;
        }
        
    
        /*
        
        if (button.pressed == FALSE && previousPressed != pressed) {
            selectedButtonData = button;
            if (onClick != NULL) onClick(this);
        }*/
    }
}


void ToggleButtonGroup::addButton(json::iterator it) {
    ButtonGroup::addButton(it);
}

