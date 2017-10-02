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
 Implements the Decorator pattern
*/
class Viewport : public Element
{
    Element *component;
public:
    float overflowX, overflowY;
    //ofRectangle totalRect;
    float scrollPositionX, scrollPositionY;
    float totalHeight;
    float totalWidth;
    
    Viewport();
    ~Viewport();
    void set(json config);
    
    virtual void update();
    virtual void draw(NVGcontext* vg);
    
    /*!
     Traverse parents and calculate the elements visible rect.
     This is the actual place on the screen this element occupies
     */
    virtual ofRectangle calculateVisibleRect();
    
    virtual string getClass() { return "Viewport";}
    
    
    ofRectangle calculateDrawingRectForElement(Element *element);

};

#endif /* Viewport_hpp */
