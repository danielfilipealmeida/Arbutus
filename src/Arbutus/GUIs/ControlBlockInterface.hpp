//
//  ControlBlockInterface.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 02/06/18.
//
//

#ifndef ControlBlockInterface_h
#define ControlBlockInterface_h


class ControlBlockInterface
{
public:
    
    /*!
     \brief Setups up the Layers controls
     */
    virtual void setup() = 0;
    
    /*!
     \brief updates this GUI part
     */
    virtual void update() = 0;
    
    /*!
     \brief sets this control block to be updated next time the ::update() method is executed
     \param _needsUpdate
     */
    virtual void setNeedsUpdate(bool _needsUpdate) = 0;
};

#endif /* ControlBlockInterface_h */
