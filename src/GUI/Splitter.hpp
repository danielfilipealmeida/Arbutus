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


/*!
 @class Splitter
 @abstract Divides the area of the parent into several elements
 @discussion Takes the entire area of the parent or the whole screen of no parent. Divides it into the given number of requested zones. each zone needs to define a percentage (float values 0 to 1).
 the total percentage must be 1.
 */
class Splitter : public Element {
protected:
    SplitterType type;
    
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

};
#endif /* Splitter_hpp */
