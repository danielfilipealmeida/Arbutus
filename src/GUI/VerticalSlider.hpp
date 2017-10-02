//
//  VerticalSlider.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 23/09/17.
//
//

#ifndef VerticalSlider_hpp
#define VerticalSlider_hpp

#include <stdio.h>
#include "Slider.hpp"


class VerticalSlider : public Slider {
public:
    VerticalSlider();
    ~VerticalSlider();
    void update();
    void draw(NVGcontext* vg);
    void set(json config);

    virtual string getClass() { return "VerticalSlider";}

};
#endif /* VerticalSlider_hpp */