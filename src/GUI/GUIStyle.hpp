//
//  style.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 12/09/17.
//
//

#ifndef style_hpp
#define style_hpp

#include <stdio.h>
#include "ofMain.h"


class GUIStyle
{
    
    GUIStyle();
    ~GUIStyle();
    
    ofColor baseColor, textColor, backgroundColor, darkColor, lightColor;
    float contrast, brightness, saturation;
    
public:
    
    static GUIStyle& getInstance();
    GUIStyle(GUIStyle const&) = delete;
    void operator=(GUIStyle const&) = delete;
    
    void calculateColors();
    ofColor getTextColor();
    ofColor getBaseColor();
    ofColor getBackgroundColor();
    ofColor getDarkColor();
    ofColor getLightColor();
    float getBrightness();
    float getSaturation();
    
    
};


#endif /* style_hpp */
