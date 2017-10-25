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
    
    //for(auto element:controlsFullState) {
        //cout << element.dump() << endl;
    
    for(json::iterator it = controlsFullState.begin(); it != controlsFullState.end(); ++it) {
        auto element = it.value();
        if (element["type"].get<string>().compare("f") == 0) {
            addFloat(element, it.key());
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
    
    //cout << sliderData.dump(4) << endl;
    
    Slider *newSlider = (Slider *) parentElement->add(GUI::getInstance().add<Slider>(sliderData));
    newSlider->setOnChange([this, _elementData, key](Slider *slider){
        
        if (this->properties == NULL) {
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
