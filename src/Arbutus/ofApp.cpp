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
    
    guiTest002();
    
    layersControls.set(Layers::getInstance().get(0)->getProperties()->getFullState());
    
    

}



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
    
    
    
    
     Slider *slider = GUI::getInstance().add<Slider>({
     {"x", 0},
     {"y", 0},
     {"width", 100},
     {"height", 32},
     {"caption", "Slider"},
     {"value", 0.2},
     {"minValue", -1.0},
     {"maxValue", 1.0}
     });
     slider->setValue(0.7);
     slider->setOnChange([](Slider *slider) {
     //Layers::getInstance().get(0)->setState({{"alpha", 1.0-slider->getValue()}});
     //Layers::getInstance().get(1)->setState({{"alpha", slider->getValue()}});
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
     {"x", 400},
     {"y", 100},
     {"width", 100},
     {"height", 100},
     {"totalWidth", 200},
     {"totalHeight", 200}
     });
     slider->setParent(viewport);
     
     
     vslider->setOnChange([viewport](Slider *vslider) {
     viewport->setScrollPositionY(vslider->getValue());
     });
     
}

void ofApp::guiTest002() {
    Splitter *splitter = GUI::getInstance().add<Splitter>({
        {"mode", SPLITTER_VERTICAL}
    });
    Viewport *viewport1 = GUI::getInstance().add<Viewport>({});
    viewport1->add(GUI::getInstance().add<Button>({
        {"caption", "Button 1"}
    }));
    viewport1->add(GUI::getInstance().add<Slider>({
        {"caption", "Slider 1"},
        {"value", 1.0}
    }));
    Preview *preview = (Preview *) viewport1->add(GUI::getInstance().add<Preview>({
        
    }));
    
    
    layersControls.setParentElement(viewport1);
    
    preview->setBuffer(Engine::getInstance()->getBuffer());
    splitter->add(viewport1, 0.3);
    
    Viewport *viewport2 = GUI::getInstance().add<Viewport>({});
    viewport2->add(GUI::getInstance().add<Button>({
        {"caption", "Button 2"}
    }));
    splitter->add(viewport2, 0.7);
    

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
