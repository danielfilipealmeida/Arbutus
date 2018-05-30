#include "ofApp.h"
#include "Engine.h"
#include "JsonLoad.hpp"
#include "GUIStyle.hpp"




//--------------------------------------------------------------
void ofApp::setup(){
    auto splitedPath = ofSplitString(ofFilePath::getCurrentExeDir(), "/");
    splitedPath.pop_back();
    splitedPath.pop_back();
    resourcesPath = ofJoinString(splitedPath, "/") + "/Resources/";
    
    
    //Engine *engine = new Engine();

    new Engine();
    ofSetWindowTitle("Arbutus");
    ofSetFrameRate(35); 
    
    devSetup();
    
    //appGui = new AppGUI();
    appGui = new NewGUI();
    appGui->setup({});

    //windows.add(window);
    json currentState = Engine::getInstance()->getState();
    cout << currentState.dump(4) << endl;
}

void ofApp::devSetup() {
    Engine *engine = Engine::getInstance();
    
    //string filePath = ofFilePath::getCurrentExeDir() + "../Resources/set.json";
    string filePath = resourcesPath + "set.json";
    
    try {
        engine->openSet(filePath);
    }
    catch (string &exception) {
        cout << "Error: " << exception << endl;
    }
    Set::getInstance().setCurrentScene(0);
    engine->play({
        {"layer", 0},
        {"column", 0}
    });
    engine->play({
        {"layer", 1},
        {"column", 0}
    });
}


//--------------------------------------------------------------
void ofApp::update(){
    Engine::getInstance()->render();
    appGui->getGUI()->update();
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(GUIStyle::getInstance().getDarkColor());
    appGui->getGUI()->draw();
    ofGetWindowPtr()->makeCurrent();
}


void ofApp::setPreviewWindow(shared_ptr<ofAppBaseWindow> _previewWindow) {
    previewWindow = _previewWindow;
}

void ofApp::setLayersWindow(shared_ptr<ofAppBaseWindow> _layersWindow)  {
    layersWindow = _layersWindow;
}




void ofApp::drawPreview(ofEventArgs & args)
{
    ofRectangle previewDrawingRect;
    previewDrawingRect.setSize(previewWindow->getWidth(), previewWindow->getHeight());
    ofClear(ofColor::black);
    ofSetColor(255,255,255);
    Engine::getInstance()->getBuffer()->getTexture().draw(previewDrawingRect);
}

void ofApp::drawLayers(ofEventArgs & args) {
    Engine *engine;
    Layers *layers;
    float currentY, previewHeight;
    
    engine = Engine::getInstance();
    layers = &Layers::getInstance();
    
    ofRectangle layersDrawingRect;
    layersDrawingRect.setSize(layersWindow->getWidth(), layersWindow->getHeight());
    ofClear(ofColor::black);
    ofSetColor(255,255,255);
    
    currentY = 0;
    previewHeight = previewWindow->getWidth() * 3 / 4;
    for (int f = 0; f < layers->count(); f++)
    {
        layers->get(f)->draw(0, currentY, previewWindow->getWidth(), previewHeight);
        currentY += previewHeight;
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
