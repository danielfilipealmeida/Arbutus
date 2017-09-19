#include "ofApp.h"
#include "Engine.h"
#include "JsonLoad.hpp"




//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Arbutus");
    
    cout << ofFilePath::getCurrentExeDir() << endl;
    Engine *engine = new Engine();
    string filePath = ofFilePath::getCurrentExeDir() + "../Resources/set.json";
    
    
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


    GUI::getInstance().add<Button>({
        {"x", 200},
        {"y", 200},
        {"width", 100},
        {"height", 32},
        {"caption", "OK"}
    });
    
    GUI::getInstance().add<Slider>({
        {"x", 200},
        {"y", 240},
        {"width", 100},
        {"height", 32},
        {"caption", "Slider"},
        {"value", 0.2},
        {"minValue", -1.0},
        {"maxValue", 1.0}
    });

}

//--------------------------------------------------------------
void ofApp::update(){
    Engine::getInstance()->render();
    GUI::getInstance().update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    Engine::getInstance()->drawOutput();
    GUI::getInstance().draw();
    
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
