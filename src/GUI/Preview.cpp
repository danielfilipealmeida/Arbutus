//
//  Preview.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 17/10/2017.
//

#include "Preview.hpp"
#include "GUIStyle.hpp"
#include "Primitives.hpp"

Preview::Preview() {
    fbo = NULL;
}

Preview::~Preview()  {
    
}


void Preview::set(json config) {
    if (!config["x"].is_number()) config["x"] = 0;
    if (!config["y"].is_number()) config["y"] = 0;
    if (!config["width"].is_number()) config["width"] = ofGetWidth();
    if (!config["height"].is_number()) config["height"] = ofGetHeight();
    
    Element::set(config);
}



void Preview::update() {
    
}



void Preview::draw(NVGcontext* vg) {
    //Element::draw(vg);
    if (fbo == NULL) return;
    
    fbo->draw(rect);
  
    nvgBeginPath(vg);
    nvgRect(vg, rect.x, rect.y, rect.width, rect.height);
    nvgStrokeColor(vg, ofColor2NVGColor(ofColor::black, 255));
    nvgStroke(vg);
}


void Preview::setBuffer(ofFbo *_fbo) {
    fbo = _fbo;
}

/*
float Preview::getAspectRatio()
{
    if (fbo == NULL) {
        return 4.0 / 3.0;
    }
    
    return fbo->getTexture().texData.tex_w / fbo->getTexture().texData.tex_h;
}
*/


float Preview::getHeightForWidth(float _width) {
    float height, originalAspectRatio;
    
    originalAspectRatio = (fbo != NULL) ? (fbo->getTexture().texData.tex_w / fbo->getTexture().texData.tex_h) : (4.0/3.0);
    
    return _width / originalAspectRatio;
}
