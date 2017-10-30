//
//  Windows.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 28/10/2017.
//

#include "Windows.hpp"
#include "Engine.h"


Windows::Windows() {
    
}

Windows::~Windows()  {
    
}

void Windows::add(shared_ptr<ofAppBaseWindow> mainWindow)  {
    ofGLFWWindowSettings settings;
    settings.shareContextWith = mainWindow;
    settings.width = 640;
    settings.height = 480;
    settings.setPosition(ofVec2f(0,0));
    shared_ptr<ofAppBaseWindow> secundaryWindow = ofCreateWindow(settings);
    secundaryWindow->setWindowTitle("Output " + std::to_string(windowApps.size() + 1));
    
    shared_ptr<SecundaryWindowApp> secundaryWindowApp(new SecundaryWindowApp);
    secundaryWindowApp->setWindow(secundaryWindow);
    windowApps.push_back(secundaryWindowApp);
    ofRunApp(secundaryWindow, secundaryWindowApp);
}
