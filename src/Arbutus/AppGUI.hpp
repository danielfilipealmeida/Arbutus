//
//  AppGUI.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 26/10/2017.
//

#ifndef AppGUI_hpp
#define AppGUI_hpp

#include "ofMain.h"
#include "GUI.hpp"
#include "ControlsGroup.hpp"

class AppGUI {
    GUI *gui;
    ControlsGroup layersControls;
    Splitter *splitter;
    
    Splitter *mainSplitter, *layer1Splitter, *layer2Splitter;
    
public:
    AppGUI();
    ~AppGUI();
    
    void setup(string resourcesPath);
    Element* getMainOutputViewport();
    Element* getLayerPreviewAndInfo(unsigned int layerNumber);
    Element* getLayerViewport(unsigned int layerNumber);
    Element* getVisualInstanceAtLayer(unsigned int layerNumber);
};

#endif /* AppGUI_hpp */
