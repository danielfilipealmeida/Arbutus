//
//  VisualsListControl.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 06/06/18.
//
//

#ifndef VisualsListControl_hpp
#define VisualsListControl_hpp

#include "ofMain.h"
#include "ControlsGroup.hpp"
#include "GUIInterface.h"
#include "ControlBlockInterface.hpp"

class VisualsListControls : public ControlBlockInterface
{
    GUI *gui;
    GUIInterface *guiInterface;
    ControlsGroup layersControls;
    ImageMatrix *imageMatrix;
    
    Viewport *viewport;
    //Label *label;

    
    bool needsUpdate;
    
public:
    
    /*!
     \brief Constructor. sets up the main gui pointer
     */
    VisualsListControls(GUI *_gui, GUIInterface *_guiInterface);
    
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
    void addElements();
    
    
};

#endif /* VisualsListControl_hpp */
