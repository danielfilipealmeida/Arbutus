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

class GUI
{
    int fontNormal, fontBold, fontIcons, fontEmoji;

    Button testButton;
public:
    GUI();
    ~GUI();
    void draw();
    void loadFonts();
};

#endif /* GUI_hpp */
