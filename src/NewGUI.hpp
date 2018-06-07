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
#include "VisualsControls.hpp"
#include "VisualsListControl.hpp"


#include <vector>


typedef enum AvailableControlBlocks{
    CTRLBLOCK_LAYERS = 0,
    CTRLBLOCK_VISUALS
};

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
    Splitter *splitter;
    
    Preview *mainOutput;
    std::vector<Preview *> channelsOutput;

    float previewWidth, previewHeight;
    
    VisualsListControls *visualsListControls;
    LayersControls *layersControls;
    VisualsControls *visualsControls;
    
    float x, y, width, height;
    
public:
    
    /*!
     \brief Constructor
     */
    NewGUI();
    
    /*!
     \brief Sets up the GUI implementation
     \param configuration the configuration
     */
    void setup (json configuration);
    
    /*!
     \brief Returns the current GUI
     */
    GUI* getGUI();
    
    /*!
     \brief Updates all blocks that are set for update
     */
    void update(bool force = false);
    
    
    /*!
     \brief Returns a control block
     \param AvailableControlBlocks block the block
     */
    ControlBlockInterface* getControlBlock(AvailableControlBlocks block);
    
protected:

    
    ControlsGroup getLayerControls(unsigned int layerNumber);

};

#endif /* NewGUI_hpp */
