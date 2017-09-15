//
//  Element.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#ifndef Element_hpp
#define Element_hpp

#include <stdio.h>
#include "ofMain.h"
#include "nanovg.h"


class Element
{
public:
    Boolean hover;
    Boolean pressed;
    Boolean entered;
    Boolean exited;
    
    ofRectangle rect;

    Element();
    ~Element();
    
    /*!
     Checks if the mouse is hover and if the element is being pressed
     */
    virtual void update();
    
    /*!
     Draws. Method to be overriden by childs
     */
    virtual void draw(NVGcontext* vg);
    
};

#endif /* Element_hpp */
