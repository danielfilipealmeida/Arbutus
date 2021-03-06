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
     \brief ...
     */
    void setProperties(Properties *_properties);
    
    /*!
     \brief ...
     */
    Element* addFloat(json _elementData, string key);
    
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
};

#endif /* ControlsGroup_hpp */
