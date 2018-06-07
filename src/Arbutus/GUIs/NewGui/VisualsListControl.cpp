//
//  VisualsListControl.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 06/06/18.
//
//

#include "VisualsListControl.hpp"
#include "Utils.h"


VisualsListControls::VisualsListControls(GUI *_gui, GUIInterface *_guiInterface)
{
    gui = _gui;
    guiInterface = _guiInterface;
    needsUpdate = false;
}


void VisualsListControls::setup()
{
    float width, x;
    
    width = ofGetWidth() / 3.0;
    x = 0;
    viewport = gui->add<Viewport>({
        {"x", x},
        {"y", 0},
        {"width", width},
        {"height", ofGetHeight()}
    });
    
    addElements();
}



void VisualsListControls::update()
{
    
}



void VisualsListControls::setNeedsUpdate(bool _needsUpdate)
{
    
}


void VisualsListControls::addElements() {
   
    imageMatrix = (ImageMatrix*) viewport->add(gui->add<ImageMatrix>({
        {"height", ofGetHeight()},
        {"width", 0},
        {"columns", 6},
        {"rows", 14}
    }));
    
    for(auto index = 0;
        index < Visuals::getInstance().count();
        index++) {
        Visual *visual = Visuals::getInstance().get(index);
        imageMatrix->addImage(visual->getScreenshot());
    }
}
