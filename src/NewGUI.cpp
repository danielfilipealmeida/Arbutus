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
    
    layersControls = new LayersControls(gui);
    layersControls->setup();
    
}


