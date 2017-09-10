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
#include "json.hpp"
#include "nanovg.h"

using json = nlohmann::json;

class Button : Element
{
    Boolean pushed;
    string caption;
public:
    
    Button();
    ~Button();
    void draw(NVGcontext* vg);
    void set(json buttonConfig);
};

#endif /* Button_hpp */
