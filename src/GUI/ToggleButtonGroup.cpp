//
//  ToggleButtonGroup.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "ToggleButtonGroup.hpp"
#include "GUI.hpp"

void ToggleButtonGroup::addButton(json::iterator it) {
    auto buttonData = *it;
    unsigned int icon = buttonData["icon"].is_number_integer() ? buttonData["icon"].get<unsigned int>() : 0;
    
    ToggleButton *button = GUI::getInstance().add<ToggleButton>({
        {"x", currentX},
        {"y", 0},
        {"width", buttonsWidth},
        {"height", rect.height},
        {"caption", buttonData["title"]},
        {"icon", icon}
    });
    button->setParent(this);
    
    button->setOnClick([this, it](ToggleButton *button) mutable {
        this->unpushAllExcept(button);
        this->setIterator(it);
        onClick(this);
    });
    buttons.push_back(button);
}

void ToggleButtonGroup::unpushAll() {
    for (ToggleButton* togglebutton:buttons) {
        togglebutton->setPushed(false);
    }
}

void ToggleButtonGroup::unpushAllExcept(ToggleButton *tbToKeepUntouched) {
    for (ToggleButton* togglebutton:buttons) {
        if (togglebutton != tbToKeepUntouched) togglebutton->setPushed(false);
    }
}
