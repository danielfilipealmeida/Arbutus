#include "ofMain.h"
#include "ofApp.h"


#define CATCH_CONFIG_RUNNER
#include "catch.hpp"


//========================================================================
int main( ){
    shared_ptr<ofAppBaseWindow> mainWindow;
    ofApp *mainApp;
   
    ofGLWindowSettings settings;
    settings.width = 1280;
    settings.height = 800;
    mainWindow = ofCreateWindow(settings);
    mainApp = new ofApp();
    // mainApp->setWindow(mainWindow);
    ofRunApp(mainApp);
    
}
