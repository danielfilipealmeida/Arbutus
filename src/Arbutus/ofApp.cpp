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
    
    appGui.setup();
    //guiTest002();
    
    /*
    LayerProperties *layerProperties = Layers::getInstance().get(0)->getProperties();
    layersControls.set(layerProperties->getFullState());
    layersControls.setProperties(layerProperties);
    */

    windows.add(window);
}

/*

void ofApp::guiTest001() {
    
     Element *element = GUI::getInstance().add<Element>({
     {"x", 100},
     {"y", 100},
     {"width", 200},
     {"height", 200},
     });
    
    Button *button = GUI::getInstance().add<Button>({
        {"x", 10},
        {"y", 10},
        {"width", 100},
        {"height", 32},
        {"caption", "OK"}
    });
    button->setParent(element);
    
    button->setOnClick([](Button *button){
        cout << "button clicked!" << button << endl;
    });
    
     VerticalSlider *vslider = GUI::getInstance().add<VerticalSlider>({
     {"x", 400},
     {"y", 240},
     {"width", 32},
     {"height", 100},
     {"caption", "Slider2"},
     {"value", 0.2},
     {"minValue", -1.0},
     {"maxValue", 1.0}
     });
     button->setParent(NULL);
     
     
     
     Viewport *viewport = GUI::getInstance().add<Viewport>({
         {"x", 440},
         {"y", 10},
         {"width", 250},
         {"height", 200},
         {"totalWidth", 200},
         {"totalHeight", 400}
     });

    
    for (unsigned int f=0; f<9;f++) {
        GUI::getInstance().add<Slider>({
            {"x", 4},
            {"y", (4 + f * 34)},
            {"width", 100},
            {"height", 32},
            {"caption", "Slider"},
            {"value", 0.2},
            {"minValue", -1.0},
            {"maxValue", 1.0}
        })->setParent(viewport);
        
        GUI::getInstance().add<Button>({
            {"x",110},
            {"y", (4 + f * 34)},
            {"width", 100},
            {"height", 32},
            {"caption", "OK"}
        })->setParent(viewport);
    }
   
     
     vslider->setOnChange([viewport](Slider *vslider) {
     viewport->setScrollPositionY(vslider->getValue());
     });
     
}

void ofApp::guiTest002() {
    Splitter *splitter = GUI::getInstance().add<Splitter>({
        {"mode", SPLITTER_VERTICAL}
    });
    Viewport *viewport1 = GUI::getInstance().add<Viewport>({});

    splitter->add(viewport1, 0.20);
    
    Preview *previewOutput = (Preview *) viewport1->add(GUI::getInstance().add<Preview>({
        {"caption", "Output"}
    }));
    previewOutput->setBuffer(Engine::getInstance()->getBuffer());
    Preview *previewChannel1 = (Preview *) viewport1->add(GUI::getInstance().add<Preview>({
        {"caption", "Layer 1"}
    }));
     previewChannel1->setBuffer(Layers::getInstance().get(0)->getBuffer());
    Preview *previewChannel2 = (Preview *) viewport1->add(GUI::getInstance().add<Preview>({
        {"caption", "Layer 2"}
    }));
    previewChannel2->setBuffer(Layers::getInstance().get(1)->getBuffer());
    
    layersControls.setParentElement(viewport1);
    
   
    
    
    Viewport *viewport2 = GUI::getInstance().add<Viewport>({});
    viewport2->add(GUI::getInstance().add<Button>({
        {"caption", "Button 2"}
    }));
    splitter->add(viewport2, 0.7);
    

}

void ofApp::guiTest003() {
    for (unsigned int f=0; f<6;f ++) {
        
        GUI::getInstance().add<Slider>({
            {"x", 4},
            {"y", (4 + f*36)},
            {"width", 100},
            {"height", 32},
            {"caption", "Slider"},
            {"value", 0.2},
            {"minValue", -1.0},
            {"maxValue", 1.0}
        });
    }
}
*/

//--------------------------------------------------------------
void ofApp::update(){
    Engine::getInstance()->render();
    GUI::getInstance().update();

}

//--------------------------------------------------------------
void ofApp::draw(){
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
