//
//  LayersControls.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 04/04/18.
//
//

#ifndef LayersControls_hpp
#define LayersControls_hpp

#include "ofMain.h"
#include "ControlsGroup.hpp"
#include "GUIInterface.h"

class LayersControls
{
    GUI *gui;
    ControlsGroup layersControls;
    
    Viewport *viewport;
    Label *label;
    ButtonGroup *navigationButtons;

    
public:
    /*!
     
     */
    LayersControls(GUI *_gui);
    
    void setup();
    
};

#endif /* LayersControls_hpp */
