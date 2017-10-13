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
