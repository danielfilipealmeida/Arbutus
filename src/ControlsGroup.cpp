//
//  ControlsGroup.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 21/10/2017.
//

#include "ControlsGroup.hpp"

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
    
    for(auto element:controlsFullState) {
        cout << element.dump() << endl;
        
        if (element["type"].get<string>().compare("f") == 0) {
            addFloat(element);
        }
        
    }
}


void ControlsGroup::addFloat(json _elementData) {
    json sliderData = {
        {"caption", _elementData["title"].get<string>()},
        {"minValue", (float) _elementData["min"].get<float>()},
        {"maxValue", (float) _elementData["max"].get<float>()},
        {"value", (float) _elementData["value"].get<float>()}
    };
    
    cout << sliderData.dump(4) << endl;
    
    Element *newElement = parentElement->add(GUI::getInstance().add<Slider>(sliderData));

}


void ControlsGroup::setParentElement(Element *_element) {
    parentElement = _element;
}
