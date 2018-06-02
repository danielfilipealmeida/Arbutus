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
    GUIInterface *guiInterface;
    ControlsGroup layersControls;
    
    Viewport *viewport;
    Label *label;
    ButtonGroup *navigationButtons;

    
public:
    /*!
     \brief Constructor. sets up the main gui pointer
     */
    LayersControls(GUI *_gui, GUIInterface *_guiInterface);
    
    /*!
     \brief Setups up the Layers controls
     */
    void setup();
    
    /*!
     \brief updates this GUI part
     */
    void update();
    
private:
    
    /*!
     \brief ...
     */
    ControlsGroup getLayerControls(unsigned int layerNumber, Element *parentElement);
    
    
    /*!
     \brief ...
     */
    void createGUIForLayer(unsigned int layerNumber);
    
    /*!
     \brief ...
     */
    void addCaptionAndNavigator();
    
    /*!
     \brief ...
     */
    void addElements();
    
};

#endif /* LayersControls_hpp */
