//
//  ControlsGroup.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 21/10/2017.
//

#include "ControlsGroup.hpp"

//#define EXECUTE_SET(FUNC, PARAMS) set(FUNC)((PARAMS))
#define EXECUTE_SET(func, params) func##params

ControlsGroup::ControlsGroup() {
    properties = NULL;
    parentElement = NULL;
}

ControlsGroup::~ControlsGroup()  {
    
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
        string type = element["type"].get<string>();
        
        if (type.compare("f") == 0) {
            addFloat(element, controlName);
        }
        else if (type.compare("button_group") == 0) {
            addButtonGroup(element, controlName);
        }
        else if (type.compare("toggle_button_group") == 0) {
            addToggleButtonGroup(element, controlName);
        }
        
    }
}


void ControlsGroup::addFloat(json _elementData, string key) {
    json sliderData = {
        {"caption", _elementData["title"].get<string>()},
        {"minValue", (float) _elementData["min"].get<float>()},
        {"maxValue", (float) _elementData["max"].get<float>()},
        {"value", (float) _elementData["value"].get<float>()},
        {"defaultValue", (float) (_elementData["value"].is_number() ? _elementData["value"].get<float>() : 0.0)}
    };
    
    Slider *newSlider = new Slider();
    ResetButtonDecorator *sliderWithReset = new ResetButtonDecorator(newSlider);
    sliderWithReset->set(sliderData);
    GUI::getInstance().add(sliderWithReset);
    sliderWithReset->setParent(parentElement);
    Properties *properties = this->properties;
    newSlider->setOnChange([properties, _elementData, key](Slider *slider) mutable {
        if (properties == NULL) {
            return;
        }
        properties->set(key, slider->getValue());
    });
    
    return;
    /*
    
    Slider *newSlider = (Slider *) parentElement->add(GUI::getInstance().add<Slider>(sliderData));
    Properties *properties = this->properties;
    newSlider->setOnChange([properties, _elementData, key](Slider *slider) mutable {
        if (properties == NULL) {
            return;
        }
        properties->set(key, slider->getValue());
    });
     */
}

void ControlsGroup::addButtonGroup(json _elementData, string key) {
    json buttonGroupData = {
        {"caption", _elementData["title"].get<string>()},
        {"options", _elementData["options"]},
        {"value", (float) _elementData["value"].get<float>()}
        
    };
    Label *buttonGroupLabel = (Label *) parentElement->add(GUI::getInstance().add<Label>({
        {"caption", _elementData["title"].get<string>()}
    }));
    ButtonGroup *buttonGroup = (ButtonGroup *) parentElement->add(GUI::getInstance().add<ButtonGroup>(buttonGroupData));
}

void ControlsGroup::addToggleButtonGroup(json _elementData, string key) {
    json toggleButtonGroupData = {
        {"caption", _elementData["title"].get<string>()},
        {"options", _elementData["options"]},
        {"value", (float) _elementData["value"].get<float>()}
        
    };
    Label *toggleButtonGroupLabel = (Label *) parentElement->add(GUI::getInstance().add<Label>({
        {"caption", _elementData["title"].get<string>()}
    }));
    Properties *properties = this->properties;
    ToggleButtonGroup *toggleButtonGroup = (ToggleButtonGroup *) parentElement->add(GUI::getInstance().add<ToggleButtonGroup>(toggleButtonGroupData));
    toggleButtonGroup->setOnClick([properties, _elementData, key](ToggleButtonGroup *toggleButtonGroup) mutable {
        if (properties == NULL) {
            return;
        }
        unsigned int value = toggleButtonGroup->getValue();
        
        properties->set(key, value);
    });
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
