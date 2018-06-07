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
    needsUpdate = false;
}

void VisualsControls::setup()
{
    unsigned int x;
    unsigned int width;
    
    width = ofGetWidth() / 3.0;
    x = width*2;
    
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
    string caption;
    
    caption = (visualInstance != NULL) ? visualInstanceProperties->getName() : "[invalid visual]";
    
    label = (Label *) viewport->add(gui->add<Label>({
        {"caption", caption}
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
    
    imageMatrix = (ImageMatrix*) viewport->add(gui->add<ImageMatrix>({
        {"height", 128.0},
        {"width", 0},
        {"columns", 6},
        {"rows", 2}
    }));
    VisualInstances *currentVisualInstances = Engine::getInstance()->getCurrentVisualInstances();
    for(unsigned int pos = 0;
        pos < currentVisualInstances->countInLayer(currentLayer);
        pos++) {
        
        VisualInstance *vi = currentVisualInstances->get(currentLayer, pos);
        
        if (vi!=NULL){
            // todo: visual ::getScreenshot
            imageMatrix->addImage(vi->visual->getScreenshot());
        }
        
    }

    
    navigationButtons->setOnClick([this] (ButtonGroup *buttonGroup) {
        string lastButtonCaption;
        Engine *engine = Engine::getInstance();
        
        VisualInstances visualInstances = Set::getInstance().getCurrentScene()->visualInstances;
        
        lastButtonCaption = buttonGroup->getLastClickedButtonData().caption;
        
        if (lastButtonCaption.compare("First") == 0) {
            engine->playFirstVisualInstanceOnActiveLayer();
        }
        else if (lastButtonCaption.compare("Previous") == 0) {
            engine->playPreviousVisualInstanceOnActiveLayer();
        }
        else if (lastButtonCaption.compare("Next") == 0) {
            engine->playNextVisualInstanceOnActiveLayer();
        }
        else if (lastButtonCaption.compare("Last") == 0) {
            engine->playLastVisualInstanceOnActiveLayer();
        }
        
        needsUpdate = true;
        guiInterface->update();
        
    });
    
    if (visualInstance != NULL) {
        visualInstanceControls = getVisualInstanceControls(visualInstanceProperties, viewport);
    }
}

ControlsGroup VisualsControls::getVisualInstanceControls(
                                                         VisualInstancesProperties *properties,
                                                         Element *parentElement
                                                         )
{
    ControlsGroup controls;
    
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


void VisualsControls::update()
{
    if (needsUpdate == false) return;
    
    viewport->empty();
    this->addElements();
    needsUpdate = false;
}


void VisualsControls::setNeedsUpdate(bool _needsUpdate) {
    needsUpdate = _needsUpdate;
}
