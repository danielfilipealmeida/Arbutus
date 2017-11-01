//
//  ButtonGroup.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "ButtonGroup.hpp"
#include "GUI.hpp"



ButtonGroup::ButtonGroup()
{
    currentX = GUI_BORDER;
}

ButtonGroup::~ButtonGroup()
{
    
}

void ButtonGroup::update()
{
    
}

void ButtonGroup::draw(NVGcontext* vg)
{
    Element::draw(vg);
    Element::finishDraw(vg);
}

void ButtonGroup::set(json config)
{
    Element::set(config);
    options = config["options"];
    nButtons = options.size();
    
    createButtons();
}

float ButtonGroup::calculateButtonsWidth() {
    return (rect.width - (GUI_BORDER * (nButtons + 1)))/ (float) nButtons;
}

void ButtonGroup::createButtons() {
    buttonsWidth = calculateButtonsWidth();

    for(json::iterator it = options.begin(); it!=options.end(); it++) {
        addButton(it);
        currentX = currentX + buttonsWidth + GUI_BORDER;
    }
}

void ButtonGroup::addButton(json::iterator it) {
    auto buttonData = *it;
    unsigned int icon = buttonData["icon"].is_number_integer() ? buttonData["icon"].get<unsigned int>() : 0;
    
    Button *button = GUI::getInstance().add<Button>({
        {"x", currentX},
        {"y", 0},
        {"width", buttonsWidth},
        {"height", rect.height},
        {"caption", buttonData["title"]},
        {"icon", icon}
    });
    button->setParent(this);
    
    button->setOnClick([this, it](Button *button) mutable {
        cout << "here" << endl;
        this->setIterator(it);
        onClick(this);
    });
     buttons.push_back(button);
}

void ButtonGroup::setIterator(json::iterator it) {
    selectedButtonIterator = it;
}

json::iterator ButtonGroup::getIterator() {
    return selectedButtonIterator;
}

json ButtonGroup::getLastClickedButtonData() {
    return *selectedButtonIterator;
}

void ButtonGroup::setOnClick(std::function<void(ButtonGroup *buttonGroup)> _onClick) {
    onClick = _onClick;
}
