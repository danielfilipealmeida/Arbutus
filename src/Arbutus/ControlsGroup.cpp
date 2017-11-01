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
    cout << data.dump(4) << endl;
    createGUIElements();
}

void ControlsGroup::createGUIElements() {
    if (parentElement == NULL) return;

    for(auto item:controlsDisplayOrder) {
        string controlName = item.get<string>();
        auto element = controlsFullState[controlName];
        
        if (element["type"].get<string>().compare("f") == 0) {
            addFloat(element, controlName);
        }
    }
}


void ControlsGroup::addFloat(json _elementData, string key) {
    json sliderData = {
        {"caption", _elementData["title"].get<string>()},
        {"minValue", (float) _elementData["min"].get<float>()},
        {"maxValue", (float) _elementData["max"].get<float>()},
        {"value", (float) _elementData["value"].get<float>()}
    };
    
    Slider *newSlider = (Slider *) parentElement->add(GUI::getInstance().add<Slider>(sliderData));
    Properties *properties = this->properties;
    newSlider->setOnChange([properties, _elementData, key](Slider *slider) mutable {
        if (properties == NULL) {
            return;
        }
        properties->set(key, slider->getValue());
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
