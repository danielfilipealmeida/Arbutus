//
//  VisualsControls.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 31/05/18.
//
//

#ifndef VisualsControls_hpp
#define VisualsControls_hpp

#include "ofMain.h"
#include "ControlsGroup.hpp"
#include "GUIInterface.h"
#include "ControlBlockInterface.hpp"


class VisualsControls : public ControlBlockInterface {

    GUI *gui;
    GUIInterface *guiInterface;
    ControlsGroup visualInstanceControls;
    
    Viewport *viewport;
    Label *label;
    ButtonGroup *navigationButtons;
    
    bool needsUpdate;
    
public:
    
    /*!
     \brief ...
     */
    VisualsControls(GUI *_gui, GUIInterface *_guiInterface);
    
    /*!
     \brief ...
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
    void addElements();
    
    /*!
     \brief Returns the control group for the desired visual
     */

    ControlsGroup getVisualInstanceControls(VisualInstancesProperties *properties, Element *parentElement);
};

#endif /* VisualsControls_hpp */
