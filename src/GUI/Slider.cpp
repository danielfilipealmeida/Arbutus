//
//  Slider.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 14/09/17.
//
//

#include "Slider.hpp"
#include "Primitives.hpp"
#include "GUIStyle.hpp"


Slider::Slider()
{
    
}


Slider::~Slider()
{
    
}

void Slider::update() {
    float previousValue = value;
    
    Button::update();
    
    
    if(!hover) {
        if (exited && ofGetMousePressed() > 0) {
            if (ofGetMouseX() < visibleRect.x) value = minValue;
            if (ofGetMouseX() > visibleRect.x + visibleRect.width) value = maxValue;
        }
    }
    else {
        if (ofGetMousePressed() > 0) {
            value = (ofGetMouseX() - visibleRect.x) / (rect.width);
        }
    }
    
    if (previousValue != value &&
        onChange != NULL)
    {
        onChange(this);
    }
}

void Slider::draw(NVGcontext* vg)
{
    ofColor backgroundColor;
    Element::draw(vg);
    if (hover == FALSE) {
        backgroundColor = GUIStyle::getInstance().getBackgroundColor();
    }
    else {
        if (pressed == TRUE) {
            backgroundColor = GUIStyle::getInstance().getDarkColor();
            
        }
        else  {
            backgroundColor = GUIStyle::getInstance().getLightColor();
            
        }
        
    }
    drawSlider(vg, value, caption, rect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
}



void Slider::set(json config) {
    //cout << config.dump(4) << endl;
    Button::set(config);
    minValue = (config["minValue"].is_number_float()) ? config["minValue"].get<float>() : 0.0;
    maxValue = (config["maxValue"].is_number_float()) ? config["maxValue"].get<float>() : 1.0;
    setValue(config["value"].is_number_float() ? config["value"].get<float>() : minValue);
}


void Slider::setValue(float _value) {
    value = ofClamp(_value, minValue, maxValue);
}


float Slider::getValue() {
    return value;
}


void Slider::setOnChange(std::function<void(Slider *slider)> _onChange) {
    onChange = _onChange;
}
