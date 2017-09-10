//
//  GUI.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "ofMain.h"

#include "Primitives.hpp"
#define NANOVG_GL2_IMPLEMENTATION
#include "nanovg_gl.h"
#include "GUI.hpp"




struct NVGcontext* vg;

/*!
 Creates the GUI
 */
GUI::GUI()
{
    vg = nvgCreateGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);

    loadFonts();

    testButton.set({
        {"x", 10},
        {"y", 10},
        {"width", 100},
        {"height", 20},
        {"caption", "A Button"}
    });
}

/*!
 Destroys the GUI
 */
GUI::~GUI()
{
    free(vg);
}

void GUI::loadFonts() {
    fontIcons = nvgCreateFont(vg, "icons", "../Resources/entypo.ttf");
    if (fontIcons == -1) throw ("Could not add font icons");
    
    fontNormal = nvgCreateFont(vg, "sans", "../Resources/Roboto-Regular.ttf");
    if (fontNormal == -1) throw("Could not add font italic.");
    
    fontBold = nvgCreateFont(vg, "sans-bold", "../Resources/Roboto-Bold.ttf");
    if (fontBold == -1) throw("Could not add font bold");
    
    fontEmoji = nvgCreateFont(vg, "emoji", "../Resources/NotoEmoji-Regular.ttf");
    if (fontEmoji == -1) throw("Could not add font emoji");

}

/*!
 Draws the GUI
 */
void GUI::draw()
{
    nvgBeginFrame(vg, ofGetWidth(), ofGetHeight(), 1);
    nvgBeginPath(vg);
    nvgRect(vg, 100,100, 120,30);
    nvgFillColor(vg, nvgRGBA(255,192,0,255));
    nvgFill(vg);
    nvgEndFrame(vg);
    
    drawSlider(vg, 0.5, 400, 430, 100, 20);

    testButton.draw(vg);
    
}
