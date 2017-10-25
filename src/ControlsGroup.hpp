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
    void addFloat(json _elementData, string key);
    
};

#endif /* ControlsGroup_hpp */
