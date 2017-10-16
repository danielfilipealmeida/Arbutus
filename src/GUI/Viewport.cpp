//
//  Viewport.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 22/09/17.
//
//

#include "Viewport.hpp"


Viewport::Viewport() {
    scrollPositionX = scrollPositionY = 0;
}


Viewport::~Viewport()  {
    
    
}


void Viewport::set(json config) {
    if (!config.is_object()) {
        config["x"] = 0;
        config["y"] = 0;
        config["width"] = ofGetWidth();
        config["height"] = ofGetHeight();
    }
    
    Element::set(config);
    
    totalWidth = config["totalWidth"].is_number() ? config["totalWidth"].get<float>() : rect.width;
    totalHeight = config["totalHeight"].is_number() ? config["totalHeight"].get<float>() : rect.height;

    if (totalWidth < rect.width) totalWidth = rect.width;
    if (totalHeight < rect.height) totalHeight = rect.height;
}

void Viewport::update()
{
    overflowX = totalWidth - rect.width;
    overflowY = totalHeight - rect.height;
    visibleRect = rect;
    visibleRect.x = overflowX * scrollPositionX;
    visibleRect.y = overflowY * scrollPositionY;

    Element::update();
}

void Viewport::draw(NVGcontext* vg) {
    Element::draw(vg);
    
    //Element::drawDebugRect(vg);
    
    Element::finishDraw(vg);
}


ofRectangle Viewport::calculateDrawingRectForElement(Element *element) {
    ofRectangle drawingRect;
    
    // todo: return empty rect if this isn't a parent of the given element
    
    
    drawingRect = element->rect;
    
    drawingRect.x = drawingRect.x - overflowX * scrollPositionX;
    drawingRect.y = drawingRect.y - overflowY * scrollPositionY;

    return drawingRect;
}


void Viewport::setScrollPositionY(float position) {
    scrollPositionY = position;
}

void Viewport::setScrollPositionX(float position) {
    scrollPositionX = position;
}

Element* Viewport::add(Element *newElement) {
    std::vector<Element*> childElements = getChildElements();
    unsigned int elementY;
    ofRectangle newElementRect = newElement->getRect();
    
    elementY = ((childElements.size() == 0) ? 0 : childElements.back()->getRect().y + childElements.back()->getRect().height) + GUI_BORDER;

    newElement->setParent(this);
    
    newElement->set({
        {"x", GUI_BORDER},
        {"y", elementY},
        {"width", getRect().width - (2*GUI_BORDER)},
        {"height", newElementRect.height}
    });

    return newElement;
}

void Viewport::resize(ofRectangle newRect) {
    Element::resize(newRect);
    
    for(auto element:getChildElements()) {
        ofRectangle elementRect = element->getRect();
        
        element->set({
            {"x", elementRect.x},
            {"y", elementRect.y},
            {"width",getRect().width - (2*GUI_BORDER)},
            {"height", elementRect.height}
        });
    }
    
    
}
