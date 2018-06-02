//
//  GUIInterface.h
//  Arbutus
//
//  Created by Daniel Almeida on 30/03/2018.
//

#ifndef GUIInterface_h
#define GUIInterface_h

#include "GUI.hpp"
#include "json.hpp"

using json = nlohmann::json;

/*!
 \brief Interface for creating app interfaces
 */
class GUIInterface
{
public:
    
    /*!
     \brief Sets up the GUI
     
     \param configuration a json to send all needed configuration
     */
    virtual void setup (json configuration) = 0;
    
    
    /*!
     \brief Returns the GUI object
     */
    virtual GUI* getGUI() = 0;
    
    /*!
     \brief Updates all the blocks in the gui
     \param force ignore block update conditions
     */

    virtual void update(bool force = false) = 0;
    
    
};

#endif /* GUIInterface_h */
