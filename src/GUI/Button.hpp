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




/*!
 @class Button
 @abstract Implements a simple button
 @discussion The button have a caption and an associated lambda to be executed whenever it's pushed.
 */
class Button : public Element
{
protected:
    Boolean pushed;
    string caption;
    unsigned int icon;
    std::function<void(Button *button)> onClick = NULL;
    
public:
    
    /*!
     ...
     */
    Button() ;
    
    /*!
     ...
     */
    ~Button();
    
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

    /*!
     ...
     */
    void setOnClick(std::function<void(Button *button)> _onClick);

    /*!
     ...
     */
    virtual string getClass() { return "Button";}
    
    static ofColor getBackgroundColor(Boolean isHover, Boolean isPressed);

};

#endif /* Button_hpp */
