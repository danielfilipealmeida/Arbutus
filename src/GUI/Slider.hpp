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
    std::function<void(Slider *slider)> onChange= NULL;
public:
    
   
    
    Slider();
    ~Slider();
    void update();
    void draw(NVGcontext* vg);
    void set(json config);
    void setValue(float _value);
    float getValue();
    void setOnChange(std::function<void(Slider *slider)> _onChange);
};

#endif /* Slider_hpp */
