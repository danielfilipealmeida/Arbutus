//
//  NewGUI.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 30/03/2018.
//

#include "NewGUI.hpp"
#include "Engine.h"

NewGUI::NewGUI() {
    previewWidth = 160;
    previewHeight = 140;
}

void NewGUI::setup (json configuration)
{
    mainOutput = GUI::getInstance().add<Preview>({
        {"caption", "Output"},
        {"x", 0},
        {"y", 0},
        {"width", ofGetWidth()},
        {"height", ofGetHeight()}
    });
    mainOutput->setBuffer(Engine::getInstance()->getBuffer());
    
    createChannelsPreviews();
}


void NewGUI::createChannelsPreviews()
{
    float currentY = GUI_BORDER;
    
    for (unsigned int layerNumber = 0; layerNumber < 2; layerNumber++){
        Preview *preview = GUI::getInstance().add<Preview>({
            {"caption", "Layer " + ofToString(layerNumber+1)},
            {"x", ofGetWidth() - previewWidth - GUI_BORDER},
            {"y", currentY},
            {"width", previewWidth},
            {"height", previewHeight}
        });
        preview->setBuffer(Layers::getInstance().get(layerNumber)->getBuffer());
        channelsOutput.push_back(preview);
        currentY = currentY + previewHeight + GUI_BORDER;
    }
}
