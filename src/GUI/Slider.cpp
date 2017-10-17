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
#include "Viewport.hpp"


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

ofColor Slider::getBackgroundColor() {
    if (hover == FALSE) return GUIStyle::getInstance().getBackgroundColor();

    return (pressed) ? GUIStyle::getInstance().getDarkColor() : GUIStyle::getInstance().getLightColor();
}


void Slider::draw(NVGcontext* vg)
{
    ofRectangle drawingRect = rect;
    
    if (parent->getClass().compare("Viewport") == 0) {
        drawingRect = ((Viewport *) parent)->calculateDrawingRectForElement(this);
    }
    
    ofColor backgroundColor = getBackgroundColor();
    Element::draw(vg);
    drawSlider(vg, value, caption, drawingRect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));

    Element::finishDraw(vg);
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


