#include "ofMain.h"
#include "ofApp.h"


#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

unsigned int previewHeight;


#define PREVIEW_WIDTH 320




shared_ptr<ofAppBaseWindow> createMainWindow()
{
    shared_ptr<ofAppBaseWindow> mainWindow;
    
    ofGLFWWindowSettings settings;
    settings.width = 1280;
    settings.height = 800;
    settings.setPosition(ofVec2f(PREVIEW_WIDTH,0));
    settings.resizable = true;
    mainWindow = ofCreateWindow(settings);
    
    return mainWindow;
}

shared_ptr<ofAppBaseWindow> createPreviewWindow(shared_ptr<ofAppBaseWindow> mainWindow)
{
    shared_ptr<ofAppBaseWindow> previewWindow;
    
    previewHeight = PREVIEW_WIDTH * 3 / 4;
    
    ofGLFWWindowSettings settings;
    settings.width = PREVIEW_WIDTH;
    settings.height = previewHeight;
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = false;
    settings.decorated = false;
    settings.title = "Preview";
    settings.shareContextWith = mainWindow;
    previewWindow = ofCreateWindow(settings);
    previewWindow->setVerticalSync(false);

    return previewWindow;
}

shared_ptr<ofAppBaseWindow> createLayersWindow(shared_ptr<ofAppBaseWindow> mainWindow)
{
    shared_ptr<ofAppBaseWindow> layersWindow;
    
    ofGLFWWindowSettings settings;
    settings.width = PREVIEW_WIDTH;
    settings.height = previewHeight * 2;
    settings.setPosition(ofVec2f(0,previewHeight + 24));
    settings.resizable = false;
    settings.decorated = false;
    settings.title = "Layers";
    settings.shareContextWith = mainWindow;
    layersWindow = ofCreateWindow(settings);
    layersWindow->setVerticalSync(false);
    
    return layersWindow;
}


//========================================================================
int main(){
    shared_ptr<ofAppBaseWindow> mainWindow, previewWindow, layersWindow;
   
   
    mainWindow = createMainWindow();
    
    previewWindow = createPreviewWindow(mainWindow);
    layersWindow = createLayersWindow(mainWindow);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setPreviewWindow(previewWindow);
    mainApp->setLayersWindow(layersWindow);
    // mainApp->setWindow(mainWindow);
    
    ofAddListener(previewWindow->events().draw, mainApp.get(), &ofApp::drawPreview);
    ofAddListener(layersWindow->events().draw, mainApp.get(), &ofApp::drawLayers);
    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
    
}
