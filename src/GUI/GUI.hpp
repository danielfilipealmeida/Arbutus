//
//  GUI.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#ifndef GUI_hpp
#define GUI_hpp

#include <stdio.h>
#include "Button.hpp"
#include "Slider.hpp"


class GUI
{
    int fontNormal, fontBold, fontIcons, fontEmoji;

    std::vector<Element*> elements;
    
    GUI();
    ~GUI();
public:
    
    static GUI& getInstance();
    GUI(GUI const&) = delete;
    void operator=(GUI const&) = delete;
    
    //GUI();
    //~GUI();
    
    /*!
     Updates all elements of the GUI
     */
    void update();
    
    /*!
     Draws all visible elements of the GUI
     */
    void draw();
    
    /*!
     Load all needed fonts
     */
    void loadFonts();
    
    /*!
     Template for creating, setting and storing new elements
     */
    template<class guiClass>
    guiClass* add(json data) {
        guiClass* guiObject;
        
        guiObject = new guiClass();
        guiObject->set(data);
        elements.push_back(guiObject);
        
        return guiObject;
    };
};

#endif /* GUI_hpp */
