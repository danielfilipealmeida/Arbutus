//
//  Primitives.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "Primitives.hpp"


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


void drawButton(NVGcontext* vg, int preicon, const char* text, float x, float y, float w, float h, NVGcolor col)
{
    NVGpaint bg;
    char icon[8];
    float cornerRadius = 4.0f;
    float tw = 0, iw = 0;
    
    bg = nvgLinearGradient(vg, x,y,x,y+h, nvgRGBA(255,255,255,isBlack(col)?16:32), nvgRGBA(0,0,0,isBlack(col)?16:32));
    nvgBeginPath(vg);
    nvgRoundedRect(vg, x+1,y+1, w-2,h-2, cornerRadius-1);
    if (!isBlack(col)) {
        nvgFillColor(vg, col);
        nvgFill(vg);
    }
    nvgFillPaint(vg, bg);
    nvgFill(vg);
    
    nvgBeginPath(vg);
    nvgRoundedRect(vg, x+0.5f,y+0.5f, w-1,h-1, cornerRadius-0.5f);
    nvgStrokeColor(vg, nvgRGBA(0,0,0,48));
    nvgStroke(vg);
    
    nvgFontSize(vg, 20.0f);
    nvgFontFace(vg, "sans-bold");
    tw = nvgTextBounds(vg, 0,0, text, NULL, NULL);
    if (preicon != 0) {
        nvgFontSize(vg, h*1.3f);
        nvgFontFace(vg, "icons");
        iw = nvgTextBounds(vg, 0,0, cpToUTF8(preicon,icon), NULL, NULL);
        iw += h*0.15f;
    }
    
    if (preicon != 0) {
        nvgFontSize(vg, h*1.3f);
        nvgFontFace(vg, "icons");
        nvgFillColor(vg, nvgRGBA(255,255,255,96));
        nvgTextAlign(vg,NVG_ALIGN_LEFT|NVG_ALIGN_MIDDLE);
        nvgText(vg, x+w*0.5f-tw*0.5f-iw*0.75f, y+h*0.5f, cpToUTF8(preicon,icon), NULL);
    }
    
    nvgFontSize(vg, 20.0f);
    nvgFontFace(vg, "sans-bold");
    nvgTextAlign(vg,NVG_ALIGN_LEFT|NVG_ALIGN_MIDDLE);
    nvgFillColor(vg, nvgRGBA(0,0,0,160));
    nvgText(vg, x+w*0.5f-tw*0.5f+iw*0.25f,y+h*0.5f-1,text, NULL);
    nvgFillColor(vg, nvgRGBA(255,255,255,160));
    nvgText(vg, x+w*0.5f-tw*0.5f+iw*0.25f,y+h*0.5f,text, NULL);
}

void drawSlider(NVGcontext* vg, float pos, float x, float y, float w, float h)
{
    NVGpaint bg, knob;
    float cy = y+(int)(h*0.5f);
    float kr = (int)(h*0.25f);
    
    nvgSave(vg);
    //	nvgClearState(vg);
    
    // Slot
    bg = nvgBoxGradient(vg, x,cy-2+1, w,4, 2,2, nvgRGBA(0,0,0,32), nvgRGBA(0,0,0,128));
    nvgBeginPath(vg);
    nvgRoundedRect(vg, x,cy-2, w,4, 2);
    nvgFillPaint(vg, bg);
    nvgFill(vg);
    
    // Knob Shadow
    bg = nvgRadialGradient(vg, x+(int)(pos*w),cy+1, kr-3,kr+3, nvgRGBA(0,0,0,64), nvgRGBA(0,0,0,0));
    nvgBeginPath(vg);
    nvgRect(vg, x+(int)(pos*w)-kr-5,cy-kr-5,kr*2+5+5,kr*2+5+5+3);
    nvgCircle(vg, x+(int)(pos*w),cy, kr);
    nvgPathWinding(vg, NVG_HOLE);
    nvgFillPaint(vg, bg);
    nvgFill(vg);
    
    // Knob
    knob = nvgLinearGradient(vg, x,cy-kr,x,cy+kr, nvgRGBA(255,255,255,16), nvgRGBA(0,0,0,16));
    nvgBeginPath(vg);
    nvgCircle(vg, x+(int)(pos*w),cy, kr-1);
    nvgFillColor(vg, nvgRGBA(40,43,48,255));
    nvgFill(vg);
    nvgFillPaint(vg, knob);
    nvgFill(vg);
    
    nvgBeginPath(vg);
    nvgCircle(vg, x+(int)(pos*w),cy, kr-0.5f);
    nvgStrokeColor(vg, nvgRGBA(0,0,0,92));
    nvgStroke(vg);
    
    nvgRestore(vg);
}
