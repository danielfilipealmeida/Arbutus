//
//  ButtonGroup.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#ifndef ButtonGroup_hpp
#define ButtonGroup_hpp

#include <stdio.h>
#include "Button.hpp"


/*!
@class ButtonGroup
@abstract Implements a a group of buttons
*/
class ButtonGroup : public Element
{
protected:
    string caption;
    std::vector<Button *> buttons;
    json options;
    json::iterator selectedButtonIterator;
    unsigned long nButtons;
    float buttonsWidth, currentX;
    
    std::function<void(ButtonGroup *buttonGroup)> onClick = NULL;
    
public:
    
    /*!
     ...
     */
    ButtonGroup() ;
    
    /*!
     ...
     */
    ~ButtonGroup();
    
    /*!
     ...
     */
    virtual void update();
    
    /*!
     ...
     */
    virtual void draw(NVGcontext* vg);
    
    /*!
     ...
     */
    virtual void set(json config);
    
    virtual void createButtons();
    
    virtual void addButton(json::iterator it);

    /*!
     \brief Sets the selected iterator
     
     To be used inside the lambda that handles clicks of each button, for selecting the button pressed and be able to retrieve it.
     */
    void setIterator(json::iterator it);
    
    json::iterator getIterator();
    
    /*!
     \brief Returns a json with the data of the last clicked button
     */
    json getLastClickedButtonData();
    
    /*!
     ...
     */
    void setOnClick(std::function<void(ButtonGroup *buttonGroup)> _onClick);
    
    
    /*!
     \brief Calculate each buttons width, according to the total width and the number of buttons to display.
     
     This method takes into consideration the margin between the buttons
     */
    float calculateButtonsWidth();
    
    /*!
     \brief Sets the element that will contain this element
     */
    void setParent(Element *_parent);
    
    virtual void resize(ofRectangle newRect);
};
#endif /* ButtonGroup_hpp */
