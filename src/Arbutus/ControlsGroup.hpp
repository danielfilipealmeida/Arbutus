//
//  ControlsGroup.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 21/10/2017.
//

#ifndef ControlsGroup_hpp
#define ControlsGroup_hpp


#include <stdio.h>
#include "Engine.h"
#include "GUI.hpp"

class ControlsGroup {
    json controlsFullState;
    json controlsDisplayOrder;
    Element *parentElement;
    
    void createGUIElements();
    Properties *properties;
    
    GUI *gui;
    
    
public:
    /*!
     \brief Contructor
     */
    ControlsGroup();

    /*!
     \brief Destructor
     */
    ~ControlsGroup();
    
    /*!
     \brief ...
     */
    void set(json data);
    
    /*!
     \brief ...
     */
    void setParentElement(Element *_element);
    
    /*!
     \brief Sets the properties of the Control Group
     \param *_properties the properties
     */
    void setProperties(Properties *_properties);
    
    /*!
     \brief Adds a slider to the control. Can also add a reset button next to it
     \param _elementData slider data
     \param key 
     \param withResetButton should have a reset button. default true
     \returns the new element
     */
    Element* addFloat(json _elementData, string key, bool withResetButton = true);
    
    /*!
     \brief ...
     */
    Element* addButtonGroup(json _elementData, string key);

    
    /*!
     \brief ...
     */
    Element* addToggleButtonGroup(json _elementData, string key);
    
    /*!
     \brief ...
     */
    void setControlsDisplayOrder(json _displayOrder);
    
    /*!
     \brief returns a json with the information of the control group
     \returns a json variable
     */
    json dumpJson();
    
    void updateParentRect(Element *lastAddedElement);
    
    /*!
     \brief Sets the GUI object to be used by the Control Group
     \param GUI* gui the gui object to be stored and used by this Control Group
     */
    void setGUI(GUI *_gui);
};

#endif /* ControlsGroup_hpp */
