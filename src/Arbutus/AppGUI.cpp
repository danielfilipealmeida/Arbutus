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

void AppGUI::setup(string resourcesPath) {
    /* main splitter */
    mainSplitter = GUI::getInstance().add<Splitter>({
        {"type", SPLITTER_HORIZONTAL}
    });
    
    /* left Column - preview and other stuff */
    mainSplitter->add(getMainOutputViewport(), 0.33);
    
    /* layer 1 */
    layer1Splitter = GUI::getInstance().add<Splitter>({
        {"type", SPLITTER_VERTICAL}
    });
    layer1Splitter->add(getLayerPreviewAndInfo(0), 150, SPLITTER_MODE_FIXED);
    layer1Splitter->add(getLayerViewport(0), 0.50);
    layer1Splitter->add(getVisualInstanceAtLayer(0));
    mainSplitter->add(layer1Splitter, 0.33);
   
    /* layer 2 */
    layer2Splitter = GUI::getInstance().add<Splitter>({
        {"type", SPLITTER_VERTICAL}
    });
    layer2Splitter->add(getLayerPreviewAndInfo(1), 150, SPLITTER_MODE_FIXED);
    layer2Splitter->add(getLayerViewport(1), 0.50);
    layer2Splitter->add(getVisualInstanceAtLayer(1));
    mainSplitter->add(layer2Splitter, 0.33);
    
    
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

Element* AppGUI::getLayerPreviewAndInfo(unsigned int layerNumber) {
    Preview *previewOutput = GUI::getInstance().add<Preview>({
        {"caption", "Layer " + std::to_string(layerNumber + 1)}
    });
    previewOutput->setBuffer(Layers::getInstance().get(layerNumber)->getBuffer());
    
    return previewOutput;
}

Element* AppGUI::getVisualInstanceAtLayer(unsigned int layerNumber) {
    Viewport *viewport;
    Layer *layer;
    VisualInstance *visualInstance;
    VisualInstancesProperties *visualInstanceProperties;
    ControlsGroup controls;
    
    viewport = GUI::getInstance().add<Viewport>({});
    SliderDecorator *viewportWithSlider = new SliderDecorator(viewport);
    GUI::getInstance().add(viewportWithSlider);
    
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
    
    return viewportWithSlider;
}

Element* AppGUI::getLayerViewport(unsigned int layerNumber){
    Viewport *viewport;
    Preview *previewOutput;
    Layer *layer;
    LayerProperties *layerProperties;
    ControlsGroup controls;
    
    viewport = GUI::getInstance().add<Viewport>({});
    
    SliderDecorator *viewportWithSlider = new SliderDecorator(viewport);
    GUI::getInstance().add(viewportWithSlider);
    
    layer = Layers::getInstance().get(layerNumber);

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
    cout << viewport->dump() << endl;
    
    
    return viewportWithSlider;
}
