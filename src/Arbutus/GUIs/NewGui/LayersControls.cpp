//
//  LayersControls.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 04/04/18.
//
//

#include "LayersControls.hpp"
#include "Utils.h"


LayersControls::LayersControls(GUI *_gui, GUIInterface *_guiInterface)
{
    gui = _gui;
    guiInterface = _guiInterface;
    needsUpdate = false;
}


void LayersControls::setup()
{
    float width, x;
    
    width = ofGetWidth() / 3.0;
    x = width;
    viewport = gui->add<Viewport>({
        {"x", x},
        {"y", 0},
        {"width", width},
        {"height", ofGetHeight()}
    });	
    
    addElements();
}

void LayersControls::createGUIForLayer(unsigned int layerNumber)
{
    Layer *layer;
    LayerProperties *layerProperties;
    
    layer = Layers::getInstance().get(layerNumber);
    layerProperties = layer->getProperties();
    
    json controlsOrder = json::array({
        "alpha",
        "brightness",
        "saturation",
        "contrast",
        "red",
        "green",
        "blue",
        "blurH",
        "blurV",
        "blendMode"
    });
    json controlsFullState = layerProperties->getFullState();
    
    for(auto item:controlsOrder) {
        string controlName = item.get<string>();
        auto element = controlsFullState[controlName];
        
        StateType type = (StateType) element["type"].get<unsigned int>();
        Element *addedGUIElement;

    }
    
}

ControlsGroup LayersControls::getLayerControls(unsigned int layerNumber, Element *parentElement)
{
    
    Layer *layer;
    LayerProperties *layerProperties;
    ControlsGroup controls;
    
    layer = Layers::getInstance().get(layerNumber);
    
    // Set the controls 
    layerProperties = layer->getProperties();
    controls.setGUI(gui);
    controls.setParentElement(viewport);
    controls.setProperties(layerProperties);
    controls.setControlsDisplayOrder(json::array({
        "alpha",
        "brightness",
        "saturation",
        "contrast",
        "red",
        "green",
        "blue",
        "blurH",
        "blurV",
        "blendMode"
    }));
    
    controls.set(layerProperties->getFullState());
    
    return controls;
}

void LayersControls::addElements()
{
    label = (Label *) viewport->add(gui->add<Label>({
        {"caption", ""}
    }));
    
    
    navigationButtons = (ButtonGroup*) viewport->add(gui->add<ButtonGroup>({
        {
            "options", {
                {{"caption", "First"}},
                {{"caption", "Previous"}},
                {{"caption", "Next"}},
                {{"caption", "Last"}}
            }
        }
    }));
    
    navigationButtons->setOnClick([this] (ButtonGroup *buttonGroup) {
        string lastButtonCaption = buttonGroup->getLastClickedButtonData().caption;
        Layers *layers = &Layers::getInstance();
        
        if (lastButtonCaption.compare("First") == 0) {
            layers->activateFirst();
        }
        else if (lastButtonCaption.compare("Previous") == 0) {
            layers->activatePrevious();
        }
        else if (lastButtonCaption.compare("Next") == 0) {
            layers->activateNext();
        }
        else if (lastButtonCaption.compare("Last") == 0) {
            layers->activateLast();
        }
        
        // forcing full update. 
        guiInterface->update(true);
        
    });
    
    string layerCaption = "Layer " + ofToString(Layers::getInstance().getCurrentId() + 1);
    label->setCaption(layerCaption);
    layersControls = getLayerControls(Layers::getInstance().getCurrentId(), viewport);
}



void LayersControls::update()
{
    if (needsUpdate == false) return;

    viewport->empty();
    this->addElements();
    needsUpdate = false;
}


void LayersControls::setNeedsUpdate(bool _needsUpdate) {
    needsUpdate = _needsUpdate;
}
