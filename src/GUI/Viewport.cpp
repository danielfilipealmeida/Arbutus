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
}

void Viewport::update()
{
    Element::update();
}

void Viewport::draw(NVGcontext* vg) {
    Element::draw(vg);
    
    Element::drawDebugRect(vg);
}
