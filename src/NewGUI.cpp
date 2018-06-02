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


GUI* NewGUI::getGUI()
{
    return gui;
}


void NewGUI::setup (json configuration)
{
    Viewport *layerControlsViewport;
    
    
    gui = new GUI();
    
    layersControls = new LayersControls(gui, this);
    layersControls->setup();
   
    visualsControls = new VisualsControls(gui, this);
    visualsControls->setup();
}

void NewGUI::update(bool force) {
    if (force == true) {
        layersControls->setNeedsUpdate(true);
        visualsControls->setNeedsUpdate(true);
    }
    
    layersControls->update();
    visualsControls->update();
}


ControlBlockInterface* NewGUI::getControlBlock(AvailableControlBlocks block) {
    switch (block) {
        case CTRLBLOCK_LAYERS:
            return layersControls;
            
        case CTRLBLOCK_VISUALS:
            return visualsControls;
    }
}
