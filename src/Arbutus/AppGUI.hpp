//
//  AppGUI.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 26/10/2017.
//

#ifndef AppGUI_hpp
#define AppGUI_hpp

#include "ofMain.h"
#include "ControlsGroup.hpp"
#include "GUIInterface.h"

class AppGUI : public GUIInterface
{
    GUI *gui;
    ControlsGroup layersControls;
    Splitter *splitter;
    
    Splitter *mainSplitter, *layer1Splitter, *layer2Splitter;
    
public:
    AppGUI();
    ~AppGUI();
    
    void setup(json configuration);
    Element* getMainOutputViewport();
    Element* getLayerPreviewAndInfo(unsigned int layerNumber);
    Element* getLayerViewport(unsigned int layerNumber);
    Element* getVisualInstanceAtLayer(unsigned int layerNumber);
};

#endif /* AppGUI_hpp */
