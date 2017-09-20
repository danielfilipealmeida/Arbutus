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
    float value, maxValue, minValue;
    std::function<void(float _value)> onChange= NULL;
public:
    
    Slider();
    ~Slider();
    void update();
    void draw(NVGcontext* vg);
    void set(json config);
    void setOnChange(std::function<void(float _value)> _onChange);
};

#endif /* Slider_hpp */
