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

class Element
{
public:
    ofRectangle rect;

    Element();
    ~Element();
    void draw();
};

#endif /* Element_hpp */
