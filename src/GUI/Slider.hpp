//
//  Slider.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 14/09/17.
//
//

#ifndef Slider_hpp
#define Slider_hpp


#include <stdio.h>
#include "Button.hpp"

using json = nlohmann::json;

class Slider : public Button
{
public:
    std::function<void(Slider *slider)> onChange= NULL;
    
    float value, maxValue, minValue;

    
    Slider();
    ~Slider();
    void update();
    void draw(NVGcontext* vg);
    
    /*!
     Calculate the background color according to the slider state
     */
    ofColor getBackgroundColor();
    
    
    void set(json config);
    void setValue(float _value);
    float getValue();
    void setOnChange(std::function<void(Slider *slider)> _onChange);
};

#endif /* Slider_hpp */
