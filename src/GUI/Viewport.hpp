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


/*!
 @class Viewport
 @abstract Implements a scrollable area that can contain elements. The Element class already allows this but isn't scrollable. 
 @discussion
 */
class Viewport : public Element
{
protected:
    
    Element *component;
    float overflowX, overflowY;
    float scrollPositionX, scrollPositionY;
    float totalHeight;
    float totalWidth;

public:
    
    /*!
     ...
     */
    Viewport();
    
    /*!
     ...
     */
    ~Viewport();
    
    /*!
     ...
     */
    void set(json config);
    
    /*!
     ...
     */
    virtual void update();
    
    /*!
     ...
     */
    virtual void draw(NVGcontext* vg);
    
    /*!
     ...
     */
    virtual string getClass() { return "Viewport";}
    
    /*!
     ...
     */
    ofRectangle calculateDrawingRectForElement(Element *element);

};

#endif /* Viewport_hpp */
