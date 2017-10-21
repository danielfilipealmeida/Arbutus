//
//  Element.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "Element.hpp"
#include "Viewport.hpp"
#include <typeinfo>
#include "GUI.hpp"


Element::Element()
{
    parent = NULL;
    hover = FALSE;
    pressed = FALSE;
    entered = FALSE;
    exited = FALSE;
    
    rect.x = rect.y = rect.width = rect.height = -1;
}


Element::~Element()
{
    
}


void Element::update()
{
    Boolean previousHover = hover;
    visibleRect = calculateVisibleRect();
    
    if (!visibleRect.inside(ofGetMouseX(), ofGetMouseY())) {
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
    if (rect==visibleRect || parent == NULL) return;

    nvgEndFrame(vg);
    ofRectangle parentRect = parent->rect;
    ofViewport(parentRect.x,parentRect.y, parentRect.width, parentRect.height, true);
    nvgBeginFrame(vg, parentRect.width, parentRect.height, 1);
}

void Element::finishDraw(NVGcontext* vg) {
    
    // uncomment to debug
#ifdef GUIDEBUG
    drawDebugRect(vg);
#endif
    
    if (rect==visibleRect) return;
    
    nvgEndFrame(vg);
    ofViewport(0, 0, ofGetWidth(), ofGetHeight(), true);
    nvgBeginFrame(vg, ofGetWidth(), ofGetHeight(), 1);
    
}


void Element::drawDebugRect(NVGcontext* vg) {
    nvgBeginPath(vg);
    nvgFillColor(vg, nvgRGB(0,0,0));
    nvgRect(vg, rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
    nvgStroke(vg);

}


void Element::set(json config) {
    if (!config.is_object()) return;
    
    if (!config["x"].is_number()) return;
    if (!config["y"].is_number()) return;
    if (!config["width"].is_number()) return;
    if (!config["height"].is_number()) return;
    
    rect.set(config["x"].get<unsigned int>(),
             config["y"].get<unsigned int>(),
             config["width"].get<unsigned int>(),
             config["height"].get<unsigned int>());
    /*
    if (!config.is_object()) throw("not a json object");
    if (!config["x"].is_number()) throw("x not defined");
    if (!config["y"].is_number()) throw("x not defined");
    if (!config["width"].is_number()) throw("x not defined");
    if (!config["height"].is_number()) throw("x not defined");
    
    rect.set(config["x"].get<unsigned int>(),
             config["y"].get<unsigned int>(),
             config["width"].get<unsigned int>(),
             config["height"].get<unsigned int>());
     */
}



std::vector<Element*> Element::getChildElements() {
    return GUI::getInstance().filter([this](Element *element) {
        return element->parent == this;
    });
}


void Element::setParent(Element *_parent) {
    parent = _parent;
}

Element *Element::add(Element *newElement) {
    newElement->setParent(this);
    
    return newElement;
}


ofRectangle Element::calculateVisibleRect() {
    if (parent == NULL) {
        return rect;
    }
    
    ofRectangle parentRect = parent->calculateVisibleRect();
    ofRectangle visibleRect;
    
    visibleRect.x = parentRect.x + rect.x;
    visibleRect.y = parentRect.y + rect.y;
    visibleRect.width = rect.width;
    visibleRect.height = rect.height;
    
    float excessWidth = parentRect.width - (rect.width + rect.x);
    if (excessWidth > 0) rect.width - excessWidth;
    float excessHeight = parentRect.height - (rect.height + rect.y);
    if (excessHeight > 0) rect.height - excessHeight;
    
    if (parent != NULL && parent->getClass().compare("Viewport") == 0) {
        ofRectangle parentDrawingRect = ((Viewport *) parent)->calculateDrawingRectForElement(this);
        visibleRect.width = visibleRect.width +parentDrawingRect.x;
        visibleRect.height = visibleRect.height + parentDrawingRect.y;
        
    }
    
    return visibleRect;
}



string Element::description() {
    string description;
    
    return description;
}


ofRectangle Element::getRect() {
    ofRectangle returnedRect = rect;
    
    if (returnedRect.x < 0) {
        returnedRect.x = GUI_BORDER ;
    }
    if (returnedRect.y < 0) {
        returnedRect.y = GUI_BORDER;
    }
    if (returnedRect.width < 0) {
        returnedRect.width = (parent!=NULL) ? (parent->getRect().width - 2 * GUI_BORDER) : GUI_LINE_HEIGHT * 5;
    }
    if (returnedRect.height < 0) {
        returnedRect.height = GUI_LINE_HEIGHT * 1.5;
    }
    
    return returnedRect;
    
}


void Element::resize(ofRectangle newRect) {
    rect = newRect;
}


float Element::getHeightForWidth(float _width) {
    return GUI_LINE_HEIGHT * 1.5;
}

