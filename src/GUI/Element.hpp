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


#define GUIDEBUG

/*!
 GUI definitions for dimensions
 */
#define GUI_LINE_HEIGHT 18
#define GUI_BORDER GUI_LINE_HEIGHT / 4



using json = nlohmann::json;

/*!
 @class Element
 @abstract GUI Root class, from which all other GUI classes descends from
 @discussion Handles basic state and position/size. Possible events are: hover, pressed and entered. TODO (maybe) callbacks for those events. Element can also contain other elements.
 */
class Element 
{
protected:
    Element *parent;
    Boolean hover;
    Boolean pressed;
    Boolean entered;
    Boolean exited;
   
    
public:
    
    /*!
     The rectangle definition in the GUI system.
     */
    ofRectangle rect;
    
    /*!
     The rectangle definition related to the screen.
     Only represents the parts of the element that are visible, since parts can be hidden due to scrolled parents, etc.
     */
    ofRectangle visibleRect;
    
    /*!
     Rectangle definition used for drawing the rectangle.
     This is related to a parent viewport and if the vary from the `rect` if the parent is scrolled
     */
    ofRectangle drawingRect;
    
    /*!
     ...
     */
    Element();
    
    
    /*!
     ...
     */
    ~Element();
    
    
    virtual string getClass() { return "Element";}
    
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
    
    /**
     ...
     */
    std::vector<Element*> getChildElements();
    
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
    string description();
    
    /*!
     Draws a rect around the visible area of the element for debugging purposes
     */
    void drawDebugRect(NVGcontext* vg);
    
    /*!
     Get the rectangle definition of the element
     */
    ofRectangle getRect();
    
    
    /*!
     Sets the new rect
     */
    virtual void resize(ofRectangle newRect);
    
    virtual float getHeightForWidth(float _width);
    
};

#endif /* Element_hpp */
