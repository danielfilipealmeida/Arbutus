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

/*!
 @class Slider
 @abstract Implements a slider from the button
 @discussion Descends from the button but adds new behaviour by allowing the user to drag inside and set a value. This value is between a min and a max.
 */
class Slider : public Button
{
protected:
    std::function<void(Slider *slider)> onChange= NULL;
    float value, maxValue, minValue;

public:
    
    /*!
     ...
     */
    Slider();
    
    /*!
     ...
     */
    ~Slider();
    
    /*!
     ...
     */
    void update();
    
    /*!
     ...
     */
    void draw(NVGcontext* vg);
    
    /*!
     Calculate the background color according to the slider state
     */
    ofColor getBackgroundColor();
        
    /*!
     ...
     */
    void set(json config);
    
    /*!
     ...
     */
    void setValue(float _value);
    
    /*!
     ...
     */
    float getValue();
    
    /*!
     ...
     */
    void setOnChange(std::function<void(Slider *slider)> _onChange);
    
    /*!
     ...
     */
    virtual string getClass() { return "Slider";}

};

#endif /* Slider_hpp */
