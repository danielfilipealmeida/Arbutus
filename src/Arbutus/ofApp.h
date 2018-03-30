#ifndef __OF_APP__
#define __OF_APP__

#include "ofMain.h"
#include "GUI.hpp"
#include "ControlsGroup.hpp"
#include "AppGUI.hpp"
#include "NewGUI.hpp"
#include "Windows.hpp"

/*!
 @class ofApp
 @abstract ...
 @discussion ...
 */
class ofApp : public ofBaseApp {
    string resourcesPath;
    
    //AppGUI *appGui;
    NewGUI *appGui;
    Windows windows;
    shared_ptr<ofAppBaseWindow> window;
    
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void setWindow(shared_ptr<ofAppBaseWindow> _window) {window = _window;}
    
    /*!
     Setups up some data to help development
     */
    void devSetup();

    
    void guiTest001();
    void guiTest002();
    /*
    void guiTest001();
    void guiTest002();
    void guiTest003();
     */
};



#endif
