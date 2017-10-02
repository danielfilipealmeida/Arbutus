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
    std::function<void(Button *button)> onClick = NULL;
    
    Button() ;
    ~Button();
    virtual void update();
    virtual void draw(NVGcontext* vg);
    virtual void set(json config);

    void setOnClick(std::function<void(Button *button)> _onClick);

    virtual string getClass() { return "Button";}

};

#endif /* Button_hpp */
