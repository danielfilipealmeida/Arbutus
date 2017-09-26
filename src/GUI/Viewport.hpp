//
//  Viewport.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 22/09/17.
//
//

#ifndef Viewport_hpp
#define Viewport_hpp

#include <stdio.h>
#include "Element.hpp"


class Viewport : public Element
{
public:
    //ofRectangle totalRect;
    float scrollPositionX, scrollPositionY;
    float totalHeight;
    float totalWidth;
    
    Viewport();
    ~Viewport();
    void set(json config);
    
    virtual void update();
    virtual void draw(NVGcontext* vg);
};

#endif /* Viewport_hpp */
