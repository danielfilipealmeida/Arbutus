//
//  ToggleButtonGroup.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#ifndef ToggleButtonGroup_hpp
#define ToggleButtonGroup_hpp

#include <stdio.h>
#include "ButtonGroup.hpp"
#include "ToggleButton.hpp"

class ToggleButtonGroup : public ButtonGroup
{
    std::vector<ToggleButton *> buttons;
public:    
    virtual void addButton(json::iterator it);
    void unpushAll();
    void unpushAllExcept(ToggleButton * tbToKeepUntouched);

};
#endif /* ToggleButtonGroup_hpp */
