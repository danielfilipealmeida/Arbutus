//
//  LayersControls.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 04/04/18.
//
//

#include "LayersControls.hpp"

LayersControls::LayersControls(GUI *_gui)
{
    gui = _gui;
}


void LayersControls::setup()
{
    viewport = gui->add<Viewport>({
        {"x", 0},
        {"y", 0},
        {"width", ofGetWidth() / 4.0},
        {"height", ofGetHeight()}
    });	
    
    label = (Label *) viewport->add(gui->add<Label>({
        {"caption", "Layer"}
    }));
    
    
    navigationButtons = (ButtonGroup*) viewport->add(gui->add<ButtonGroup>({
        {
            "options", {
                {
                    {"caption", "First"}
                },
                {
                    {"caption", "Previous"}
                },
                {
                    {"caption", "Next"}
                },
                {
                    {"caption", "Last"}
                }
            }
        }
    }));
    
}
