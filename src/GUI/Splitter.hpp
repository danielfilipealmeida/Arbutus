//
//  Splitter.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 04/10/17.
//
//

#ifndef Splitter_hpp
#define Splitter_hpp

#include <stdio.h>
#include "Element.hpp"

typedef enum {
    SPLITTER_HORIZONTAL = 0,
    SPLITTER_VERTICAL
} SplitterType;

typedef struct {
    Element *element;
    float size;
} SplitterChild;


/*!
 @class Splitter
 @abstract Divides the area of the parent into several elements
 @discussion Takes the entire area of the parent or the whole screen of no parent. Divides it into the given number of requested zones. each zone needs to define a percentage (float values 0 to 1).
 the total percentage must be 1.
 */
class Splitter : public Element {
protected:
    SplitterType type;
    
    std::vector<SplitterChild> childs;
    
    
    void calculateRect();
    
public:
    
    /*!
     ...
     */
    Splitter();
    
    /*!
     ...
     */
    ~Splitter();

    /*!
     ...
     */
    void set(json config);
    
    /*!
     ...
     */
    void update();
    
    /*!
     ...
     */
    void draw(NVGcontext* vg);
    
    /*!
     Adds a new element to the splitter at the end
     */
    void add(Element* element, float size);
    
    
    void calculateChildsRects();

};
#endif /* Splitter_hpp */
