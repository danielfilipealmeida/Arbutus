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
    cout << config.dump(4) << endl;
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
    //if (buttonsWidth <= 0 || nButtons == 0) return;
    
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

void ButtonGroup::setParent(Element *_parent) {
    Element::setParent(_parent);
    currentX = GUI_BORDER;
    buttonsWidth = calculateButtonsWidth();
    
    for(auto button:buttons) {
        ofRectangle buttonRect = button->getRect();
        //button->setParent(_parent);
        float newX = currentX + parent->getRect().x + rect.x;
        float newY = rect.y + parent->getRect().y;
        button->set({
            {"x", newX},
            {"y", newY},
            {"width", buttonRect.width},
            {"height", buttonRect.height}
        });
        
         currentX = currentX + buttonsWidth + GUI_BORDER;
    }
}


void ButtonGroup::resize(ofRectangle newRect) {
    Element::resize(newRect);
    if (parent!=NULL) setParent(parent);
}
