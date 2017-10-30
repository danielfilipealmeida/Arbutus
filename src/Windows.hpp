//
//  Windows.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 28/10/2017.
//

#ifndef Windows_hpp
#define Windows_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Engine.h"

class SecundaryWindowApp : public ofBaseApp {
    shared_ptr<ofAppBaseWindow> window;
    shared_ptr<ofGLRenderer> gl;
public:

    void draw() {
        if (window == NULL) return;
        window->makeCurrent();
        Engine::getInstance()->getBuffer()->draw(0,0 , ofGetWidth(), ofGetHeight());
     }

    void setWindow(shared_ptr<ofAppBaseWindow> _window) {
        window = _window;
    }

    shared_ptr<ofAppBaseWindow> getWindow() {
        return window;
    }
};

class Windows
{
    std::vector<shared_ptr<SecundaryWindowApp>> windowApps;
    
public:
    Windows();
    ~Windows();
    
    void add(shared_ptr<ofAppBaseWindow> mainWindow);
};

#endif /* Windows_hpp */
