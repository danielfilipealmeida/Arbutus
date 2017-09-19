//
//  Button.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include "Element.hpp"





class Button : public Element
{
public:
    Boolean pushed;
    string caption;
    
    Button();
    ~Button();
    virtual void update();
    virtual void draw(NVGcontext* vg);
    virtual void set(json config);

};

#endif /* Button_hpp */
