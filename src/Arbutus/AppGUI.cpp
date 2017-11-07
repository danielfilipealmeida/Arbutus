//
//  AppGUI.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 26/10/2017.
//

#include "AppGUI.hpp"

AppGUI::AppGUI()  {
    
}

AppGUI::~AppGUI()  {
    
}

void AppGUI::setup() {
    splitter = GUI::getInstance().add<Splitter>({
        {"mode", SPLITTER_VERTICAL}
    });
    
    splitter->add(getMainOutputViewport(), 0.20);
    splitter->add(getLayerViewport(0), 0.20);
    splitter->add(getVisualInstanceAtLayer(0), 0.20);
    splitter->add(getLayerViewport(1), 0.20);
    splitter->add(getVisualInstanceAtLayer(0), 0.20);
}

Element* AppGUI::getMainOutputViewport(){
    Viewport *viewport;
    Preview *previewOutput;
    
    viewport = GUI::getInstance().add<Viewport>({});
    
    previewOutput = (Preview *) viewport->add(GUI::getInstance().add<Preview>({
        {"caption", "Output"}
    }));
    previewOutput->setBuffer(Engine::getInstance()->getBuffer());
    
    return viewport;
}

Element* AppGUI::getVisualInstanceAtLayer(unsigned int layerNumber) {
    Viewport *viewport;
    Layer *layer;
    VisualInstance *visualInstance;
    VisualInstancesProperties *visualInstanceProperties;
    ControlsGroup controls;
    
    viewport = GUI::getInstance().add<Viewport>({});
    layer = Layers::getInstance().get(layerNumber);
    visualInstance = layer->getActiveInstance();
    visualInstanceProperties = visualInstance->getProperties();
    controls.setParentElement(viewport);
    controls.setProperties(visualInstanceProperties);
    controls.setControlsDisplayOrder(json::array({
        "startPercentage",
        "endPercentage",
        "percentagePlayed",
        "direction",
        "loopMode",
        "zoomX",
        "zoomY",
        "centerX",
        "centerY",
        "effects_drywet",
        "triggerMode"
    }));
    controls.set(visualInstanceProperties->getFullState());
    
    return viewport;
    
    /*
     state["zoomX"] = getZoomX();
     state["zoomY"] = getZoomY();
     state["centerX"] = getCenterX();
     state["centerY"] = getCenterY();
     state["x"] = getX();
     state["y"] = getY();
     state["layer"] = getLayer();
     state["column"] = getColumn();
     state["retrigger"] = getRetrigger();
     state["isPlaying"] = getIsPlaying();
     state["percentagePlayed"] = getPercentagePlayed();
     state["startPercentage"] = getStartPercentage();
     state["endPercentage"] = getEndPercentage();
     state["effects_drywet"] = effects_drywet; // TODO: Make setter and getter
     state["loopMode"] = getLoopMode();
     state["direction"] = getDirection();
     state["beatSnap"] = getBeatSnap();
     state["isTriggered"] = getIsTriggered();
     state["openedTimestamp"] = getOpenedTimestamp();
     state["lastPlayedTimestamp"] = getLastPlayedTimestamp();
     state["triggerMode"] = getTriggerMode();
     */
}

Element* AppGUI::getLayerViewport(unsigned int layerNumber){
    Viewport *viewport;
    Preview *previewOutput;
    Layer *layer;
    LayerProperties *layerProperties;
    ControlsGroup controls;
    
    viewport = GUI::getInstance().add<Viewport>({});
    layer = Layers::getInstance().get(layerNumber);

    /* Set the viewport */
    previewOutput = (Preview *) viewport->add(GUI::getInstance().add<Preview>({
        {"caption", "Layer " + std::to_string(layerNumber + 1)}
    }));
    previewOutput->setBuffer(layer->getBuffer());
    
     /* Set the controls */
    layerProperties = layer->getProperties();
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
    
    return viewport;
}
