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
#include "json.hpp"


using json = nlohmann::json;


class Element
{
    Element *parent;
    
    
public:
    Boolean hover;
    Boolean pressed;
    Boolean entered;
    Boolean exited;
    
    ofRectangle rect;
    ofRectangle visibleRect;

    Element();
    ~Element();
    
    /*!
     Checks if the mouse is hover and if the element is being pressed
     */
    virtual void update();
    
    /*!
     Draws. Method to be overriden by childs.
     When overriding this method, the descendent needs always to run this because in here elements inside elements are properly handled.
     */
    virtual void draw(NVGcontext* vg);
    
    
    /*!
     Finishes drawing the element. Important for properly drawing elements inside other elements.
     */
    void finishDraw(NVGcontext* vg);
    
    /*!
     Sets the Rectangle 
     */
    virtual void set(json config);
    
    /*!
     Sets the element that will contain this element
     */
    void setParent(Element *_parent);
    
    /*!
     Traverse parents and calculate the elements visible rect.
     This is the actual place on the screen this element occupies
     */
    ofRectangle calculateVisibleRect();
    
    /*!
     Outputs to stdout the state of the element
     */
    void description();
    
};

#endif /* Element_hpp */
