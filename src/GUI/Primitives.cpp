//
//  Primitives.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "Primitives.hpp"
#include "GUIStyle.hpp"

// Returns 1 if col.rgba is 0.0f,0.0f,0.0f,0.0f, 0 otherwise
int isBlack(NVGcolor col)
{
    if( col.r == 0.0f && col.g == 0.0f && col.b == 0.0f && col.a == 0.0f )
    {
        return 1;
    }
    return 0;
}

static char* cpToUTF8(int cp, char* str)
{
    int n = 0;
    if (cp < 0x80) n = 1;
    else if (cp < 0x800) n = 2;
    else if (cp < 0x10000) n = 3;
    else if (cp < 0x200000) n = 4;
    else if (cp < 0x4000000) n = 5;
    else if (cp <= 0x7fffffff) n = 6;
    str[n] = '\0';
    switch (n) {
        case 6: str[5] = 0x80 | (cp & 0x3f); cp = cp >> 6; cp |= 0x4000000;
        case 5: str[4] = 0x80 | (cp & 0x3f); cp = cp >> 6; cp |= 0x200000;
        case 4: str[3] = 0x80 | (cp & 0x3f); cp = cp >> 6; cp |= 0x10000;
        case 3: str[2] = 0x80 | (cp & 0x3f); cp = cp >> 6; cp |= 0x800;
        case 2: str[1] = 0x80 | (cp & 0x3f); cp = cp >> 6; cp |= 0xc0;
        case 1: str[0] = cp;
    }
    return str;
}


void print(ofColor color) {
    printf("ofColor: r=%i, g=%i, b=%i, a=%i\n", color.r, color.g, color.b, color.a);
}

void shrinkRect(ofRectangle &rect, float pixels) {
    rect.setX(rect.getX() + pixels);
    rect.setY(rect.getY() + pixels);
    rect.setWidth(rect.getWidth() - (2*pixels));
    rect.setHeight(rect.getHeight() - (2*pixels));
    
}

NVGcolor ofColor2NVGColor(ofColor color, unsigned char alpha) {
    return nvgRGBA(color.r, color.g, color.b, alpha);
}


void drawFilledRoundRect(NVGcontext* vg, ofRectangle rect, NVGcolor col, float cornerRadius) {
    nvgBeginPath(vg);
    nvgFillColor(vg, col);
    nvgRoundedRect(
                   vg,
                   rect.getX(),
                   rect.getY(),
                   rect.getWidth(),
                   rect.getHeight(),
                   cornerRadius
                   );
    nvgFill(vg);
}


void drawStrokedRoundRect(NVGcontext* vg, ofRectangle rect, NVGcolor col, float cornerRadius) {
    nvgBeginPath(vg);
    nvgRoundedRect(
                   vg,
                   rect.getX() + 0.5f,
                   rect.getY() + 0.5f,
                   rect.getWidth() - 1,
                   rect.getHeight() - 1,
                   cornerRadius-0.5f
                   );
    nvgStrokeColor(vg, col);
    nvgStroke(vg);
    

}

void drawBox(NVGcontext* vg, ofRectangle rect, NVGcolor col, float cornerRadius)
{
    ofRectangle innerRect, outerRect;
    innerRect = outerRect = rect;
    shrinkRect(innerRect, 1);
    shrinkRect(outerRect, 0.5);
    
    drawFilledRoundRect(vg, innerRect, col, cornerRadius - 1);
    drawStrokedRoundRect(vg, outerRect, ofColor2NVGColor(ofColor::black, 255), cornerRadius - 0.5);
}


void printCenteredText(NVGcontext* vg, int preicon, string text, ofRectangle rect, NVGcolor textColor) {
    float tw = 0, iw = 0;
    char icon[8];
    
    nvgFontSize(vg, 20.0f);
    nvgFontFace(vg, "sans-bold");
    tw = nvgTextBounds(vg, 0,0, text.c_str(), NULL, NULL);
    if (preicon != 0) {
        nvgFontSize(vg, rect.getHeight() * 1.3f);
        nvgFontFace(vg, "icons");
        nvgFillColor(vg, nvgRGBA(255,255,255,96));
        nvgTextAlign(vg,NVG_ALIGN_LEFT|NVG_ALIGN_MIDDLE);
        nvgText(
                vg,
                rect.getX() + rect.getWidth() * 0.5f - tw * 0.5f - iw * 0.75f,
                rect.getY() + rect.getHeight() * 0.5f,
                cpToUTF8(preicon,icon),
                NULL
                );
    }
    
    nvgFontSize(vg, 20.0f);
    nvgFontFace(vg, "sans-bold");
    nvgTextAlign(vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
    
    nvgFillColor(vg, textColor);
    nvgText(
            vg,
            rect.getX() + rect.getWidth() * 0.5f - tw * 0.5f + iw * 0.25f,
            rect.getY() + rect.getHeight() * 0.5f,
            text.c_str(),
            NULL
            );
}

void printCenteredTextRotated90(NVGcontext* vg, string text, ofRectangle rect, NVGcolor textColor) {
    nvgFontSize(vg, 20.0f);
    nvgFontFace(vg, "sans-bold");
    nvgTextAlign(vg, NVG_ALIGN_CENTER | NVG_ALIGN_TOP);
    nvgFillColor(vg, textColor);
    
    nvgText(
        vg,
        rect.getX() + rect.getWidth() * 0.5f,
        rect.getY() + rect.getHeight() * 0.5f,
        text.c_str(),
        NULL
    );
   
}

void drawButton(NVGcontext* vg, int preicon, string text, ofRectangle rect, NVGcolor backgroundColor, NVGcolor textColor)
{
    float cornerRadius = 2.0f;
    
    drawBox(vg, rect, backgroundColor, cornerRadius);
    printCenteredText(vg, preicon, text, rect, textColor);
}

void drawSlider(NVGcontext* vg, float pos, string text, ofRectangle rect, NVGcolor backgroundColor, NVGcolor textColor, Boolean vertical)
{
    pos = ofClamp(pos, 0,1);
    float cornerRadius = 2.0f;
    
    ofRectangle innerRect, outerRect, valueRect;
    innerRect = outerRect = rect;
    shrinkRect(innerRect, 1);
    shrinkRect(outerRect, 0.5);
    
    valueRect = innerRect;
    if (!vertical ) {
        valueRect.setWidth(valueRect.getWidth() * pos);
    }
    else {
        valueRect.setHeight(valueRect.getHeight() * pos);
    }
    
    drawFilledRoundRect(vg, innerRect, backgroundColor, cornerRadius - 1);
    drawFilledRoundRect(vg, valueRect, ofColor2NVGColor(ofColor::white, 128), cornerRadius - 1);
    drawStrokedRoundRect(vg, outerRect, ofColor2NVGColor(ofColor::black), cornerRadius - 0.5);
    
    if (!vertical) printCenteredText(vg, 0, text, rect, textColor);
    else printCenteredTextRotated90(vg, text, rect, textColor);
}

