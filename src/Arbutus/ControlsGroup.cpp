//
//  ControlsGroup.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 21/10/2017.
//

#include "ControlsGroup.hpp"
#include "Utils.h"

//#define EXECUTE_SET(FUNC, PARAMS) set(FUNC)((PARAMS))
#define EXECUTE_SET(func, params) func##params

ControlsGroup::ControlsGroup() {
    properties = NULL;
    parentElement = NULL;
    gui = NULL;
}

ControlsGroup::~ControlsGroup() {}

void ControlsGroup::setGUI(GUI *_gui)
{
    gui = _gui;
}

void ControlsGroup::set(json data)  {
    controlsFullState = data;
    createGUIElements();
}

void ControlsGroup::createGUIElements() {
    if (parentElement == NULL) return;

    for(auto item:controlsDisplayOrder) {
        string controlName = item.get<string>();
        auto element = controlsFullState[controlName];
        StateType type = (StateType) element["type"].get<unsigned int>();
        Element *addedGUIElement;
        
        switch (type) {
        case StateType_Integer:
        case StateType_Float:
            addedGUIElement = addFloat(element, controlName, true);
            break;
            
        case StateType_ToggleButtonGroup:
            addedGUIElement = addToggleButtonGroup(element, controlName);
            break;
        }
        
        //updateParentRect(addedGUIElement);
    }
}


void ControlsGroup::updateParentRect(Element *lastAddedElement)
{
    ofRectangle lastAddedElementRect, currentParentRect;
    float growWidth, growHeight;

    lastAddedElementRect = lastAddedElement->getRect();
    currentParentRect = parentElement->getRect();
    growWidth = lastAddedElementRect.x + lastAddedElementRect.width + GUI_BORDER;
    growHeight = lastAddedElementRect.y + lastAddedElementRect.height + GUI_BORDER;
    currentParentRect.growToInclude(growWidth, growHeight);
    parentElement->getVisibleRectForRect(currentParentRect);
}


Element* ControlsGroup::addFloat(json _elementData, string key, bool withResetButton)
{
    json sliderData;
    Slider *newSlider;
    ResetButtonDecorator *sliderWithReset;
    Properties *properties;
    
    sliderData = {
        {"caption", _elementData["title"].get<string>()},
        {"minValue", (float) _elementData["min"].get<float>()},
        {"maxValue", (float) _elementData["max"].get<float>()},
        {"value", (float) _elementData["value"].get<float>()},
        {"defaultValue", (float) (_elementData["value"].is_number() ? _elementData["value"].get<float>() : 0.0)}
    };
    
    newSlider = new Slider();
    
    if (withResetButton) {
        sliderWithReset = new ResetButtonDecorator(newSlider);
        sliderWithReset->set(sliderData);
       
        gui->add(sliderWithReset);
        parentElement->add(sliderWithReset);
         sliderWithReset->setParent(parentElement);
    }
    else {
        newSlider->set(sliderData);
        gui->add(newSlider);
        newSlider->setParent(parentElement);
        parentElement->add(newSlider);
    }

    
    properties = this->properties;
    newSlider->setOnChange([properties, _elementData, key](Slider *slider) mutable {
        if (properties == NULL) return;
        properties->set(key, slider->getValue());
    });
    
    return newSlider;
}


Element* ControlsGroup::addButtonGroup(json _elementData, string key) {
    json buttonGroupData = {
        {"caption", _elementData["title"].get<string>()},
        {"options", _elementData["options"]},
        {"value", (float) _elementData["value"].get<float>()}
        
    };
    Label *buttonGroupLabel = (Label *) parentElement->add(gui->add<Label>({
        {"caption", _elementData["title"].get<string>()}
    }));
    ButtonGroup *buttonGroup = (ButtonGroup *) parentElement->add(gui->add<ButtonGroup>(buttonGroupData));
    
    return buttonGroup;
}


Element* ControlsGroup::addToggleButtonGroup(json _elementData, string key) {
    json toggleButtonGroupData = {
        {"caption", _elementData["title"].get<string>()},
        {"options", _elementData["options"]},
        {"value", (float) _elementData["value"].get<float>()}
        
    };
    Label *toggleButtonGroupLabel = (Label *) parentElement->add(gui->add<Label>({
        {"caption", _elementData["title"].get<string>()}
    }));
    Properties *properties = this->properties;
    ToggleButtonGroup *toggleButtonGroup = (ToggleButtonGroup *) parentElement->add(gui->add<ToggleButtonGroup>(toggleButtonGroupData));
    toggleButtonGroup->setOnClick([properties, _elementData, key](ToggleButtonGroup *toggleButtonGroup) mutable {
        if (properties == NULL) {
            return;
        }
        unsigned int value = toggleButtonGroup->getValue();
        
        properties->set(key, value);
    });
    
    return toggleButtonGroup;
}

void ControlsGroup::setParentElement(Element *_element) {
    parentElement = _element;
}

void ControlsGroup::setProperties(Properties *_properties) {
    properties = _properties;
}

void ControlsGroup::setControlsDisplayOrder(json _displayOrder) {
    controlsDisplayOrder = _displayOrder;
}


json ControlsGroup::dumpJson() {
    json state;
    
    state["controlsFullState"] = controlsFullState;
    state["controlsDisplayOrder"] = controlsDisplayOrder;
    state["parentElement"] = parentElement->jsonDump();
    state["properties"] = properties->getFullState();
    
    return state;
}
