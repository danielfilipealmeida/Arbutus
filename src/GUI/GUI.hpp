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
#include "VerticalSlider.hpp"
#include "Viewport.hpp"
#include "Splitter.hpp"

/*!
 @class GUI
 @abstract 
 @discussion
 */
class GUI
{
    
protected:
    int fontNormal, fontBold, fontIcons, fontEmoji;

    std::vector<Element*> elements;
    
    GUI();
    ~GUI();
public:
    
    static GUI& getInstance();
    GUI(GUI const&) = delete;
    void operator=(GUI const&) = delete;
    
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
    
    /*!
     Apply a lambda to all elements in the GUI
     */
    void forEach(std::function<void (Element *)> lambda);
    
    /*!
     Apply a lambda to filter from all elements of the GUI
     */
    std::vector<Element*> filter(std::function<bool (Element *)> lambda);
};

#endif /* GUI_hpp */
