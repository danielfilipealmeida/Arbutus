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
#include "ControlBlockInterface.hpp"

class LayersControls : public ControlBlockInterface
{
    GUI *gui;
    GUIInterface *guiInterface;
    ControlsGroup layersControls;
    
    Viewport *viewport;
    Label *label;
    ButtonGroup *navigationButtons;

    bool needsUpdate;
    
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
    
    /*!
     \brief sets this control block to be updated next time the ::update() method is executed
     \param _needsUpdate
     */
    void setNeedsUpdate(bool _needsUpdate);
    
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
