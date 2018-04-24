//
//  NewGUI.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 30/03/2018.
//

#ifndef NewGUI_hpp
#define NewGUI_hpp

#include <stdio.h>
#include "GUIInterface.h"
#include "GUI.hpp"
#include "LayersControls.hpp"

#include <vector>


/*!
 \brief Implements the new interface of the app
 
 Uses the GUIInterface for allowing the possibility of GUI Swaps
 
 todo:
 - create list of selected parameters
 - create parameters navigator
 - create modo for swapping trough mode
    - toggle channels
    - parameters navigator
    - selected parameters
 
 */
class NewGUI : public GUIInterface
{
    GUI *gui;
    
    Preview *mainOutput;
    std::vector<Preview *> channelsOutput;

    float previewWidth, previewHeight;
    
    LayersControls *layersControls;
    
    float x, y, width, height;
    
public:
    NewGUI();
    void setup (json configuration);
    GUI* getGUI();
    
protected:
    /*!
     \brief Creates the channels previews
     */
    void createChannelsPreviews();

};

#endif /* NewGUI_hpp */
