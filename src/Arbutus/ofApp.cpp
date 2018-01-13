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
    
    appGui.setup(resourcesPath);

    windows.add(window);
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
    GUI::getInstance().update();
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(GUIStyle::getInstance().getDarkColor());
    //Engine::getInstance()->drawOutput();
    GUI::getInstance().draw();
    //windows.drawWindow(0);
    ofGetWindowPtr()->makeCurrent();
    //cout << "val: " << val << endl;
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
