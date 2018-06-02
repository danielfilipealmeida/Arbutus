//
//  VisualsControls.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 31/05/18.
//
//

#include "VisualsControls.hpp"



VisualsControls::VisualsControls(GUI *_gui, GUIInterface *_guiInterface)
{
    gui = _gui;
    guiInterface = _guiInterface;
}

void VisualsControls::setup()
{
    unsigned int x;
    unsigned int width;
    
    width = ofGetWidth() / 2.0;
    x = width;
    
    viewport = gui->add<Viewport>({
        {"x", x},
        {"y", 0},
        {"width", width},
        {"height", ofGetHeight()}
    });
    
    addElements();
}

void VisualsControls::addElements()
{
    Layer *layer;
    VisualInstance *visualInstance;
    VisualInstancesProperties *visualInstanceProperties;
    unsigned int currentLayer;
    
    currentLayer = Layers::getInstance().getCurrentId();
    layer = Layers::getInstance().get(currentLayer);
    visualInstance = layer->getActiveInstance();
    visualInstanceProperties = visualInstance->getProperties();

    label = (Label *) viewport->add(gui->add<Label>({
        {"caption", visualInstanceProperties->getName()}
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
    
    navigationButtons->setOnClick([this] (ButtonGroup *buttonGroup) {
        string lastButtonCaption = buttonGroup->getLastClickedButtonData().caption;
        
        
        if (lastButtonCaption.compare("First") == 0) {
      
        }
        else if (lastButtonCaption.compare("Previous") == 0) {
        
        }
        else if (lastButtonCaption.compare("Next") == 0) {
        
        }
        else if (lastButtonCaption.compare("Last") == 0) {
        
        }
        
        guiInterface->update();
        
    });
    

    visualInstanceControls = getVisualInstanceControls(visualInstanceProperties, viewport);
}

ControlsGroup VisualsControls::getVisualInstanceControls(
                                                         VisualInstancesProperties *properties,
                                                         Element *parentElement
                                                         )
{
    ControlsGroup controls;
    
    cout << properties->getFullState().dump(4) << endl;
    
    controls.setGUI(gui);
    controls.setParentElement(parentElement);
    controls.setProperties(properties);
    controls.setControlsDisplayOrder(json::array({
        "startPercentage",
        "endPercentage",
        "centerX",
        "centerY",
        "zoomX",
        "zoomY",
        "effects_drywet",
        "direction",
        "loopMode",
        "triggerMode"
    }));
    
    controls.set(properties->getFullState());
    return controls;
}

/*!
 \brief updates this GUI part
 */
void VisualsControls::update()
{
    viewport->empty();
    this->addElements();
}
