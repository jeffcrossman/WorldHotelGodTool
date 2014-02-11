#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetWindowTitle("World's Hotel God Tool");
	ofBackground(0, 0, 0);
    
    particles.clear();
    
    // Load a CSV File.
	csv.loadFile(ofToDataPath("hotelsbase.txt"), "~");
    
    for(unsigned int i = 1; i < csv.numRows; i+=5){
        if (csv.data[i].size() > 21) {
            float y = (-1 * ofToFloat(csv.data[i][12])) + 90 + 5;
            float x = ofToFloat(csv.data[i][13]) + 180 + 5;
            
            if (x >= 5 && x<= 365 && y >= 5 && y <= 185) { // Can't trust data to be in range
                int star = ofToInt(csv.data[i][2]);
                if (star == 0) {
                    particles.push_back( new ofxMPMParticle(x,y, 0.0, 0.0, 231/(float)255, 76/(float)255, 60/(float)255, 0.75) );
                }
                else if (star == 1) {
                    particles.push_back( new ofxMPMParticle(x,y, 0.0, 0.0, 231/(float)255, 76/(float)255, 60/(float)255, 1.0) );
                }
                else if (star == 2) {
                    particles.push_back( new ofxMPMParticle(x,y, 0.0, 0.0, 241/(float)255, 196/(float)255, 15/(float)255, 1.0) );
                }
                else if (star == 3) {
                    particles.push_back( new ofxMPMParticle(x,y, 0.0, 0.0, 26/(float)255, 188/(float)255, 156/(float)255, 1.0) );
                }
                else if (star == 4) {
                    particles.push_back( new ofxMPMParticle(x,y, 0.0, 0.0, 52/(float)255, 152/(float)255, 219/(float)255, 1.0) );
                }
                else if (star == 5) {
                    particles.push_back( new ofxMPMParticle(x,y, 0.0, 0.0, 175/(float)255, 122/(float)255, 196/(float)255, 1.0) );
                }
                else {          // Bad Data
                    particles.push_back( new ofxMPMParticle(x,y, 0.0, 0.0, 231/(float)255, 76/(float)255, 60/(float)255, 0.75) );
                }
            }
        }
    }
    csv.clear();
    
    fluid.setGridSizeX(360 + 10);
    fluid.setGridSizeY(180 + 10);
    scaleFactor = (float)ofGetWindowWidth() / (float)fluid.getGridSizeX();
    fluid.scaleFactor = scaleFactor;
    fluid.setup(particles);
    
    if (!hascontrols)
        setupControlPanel();
}

//=========================================================================
// Set up the controls in the ofxAutoControlPanel
void testApp::setupControlPanel(){
    
	gui.setup(" World's Hotel God Tool Command Center", 10, 550, 950, 225, false);
	gui.addPanel(" ", 4);
    gui.setWhichColumn(0);
	gui.addLabel("'f' to toggle fullscreen\t\n'r' to reset visualization");
    gui.setWhichColumn(1);
    gui.addLabel("'tab' to toggle this menu\n");
    gui.setWhichColumn(2);
    gui.addLabel(" \n ");
    gui.setWhichColumn(3);
    gui.addLabel(" \n ");
	gui.setWhichColumn(0);
	gui.addSlider("Density",		"DENSITY",			5.0,	0, 30.0,	false);
	gui.addSlider("Stiffness",		"STIFFNESS",		0.0,	0, 2.0,		false);
    gui.setWhichColumn(1);
	gui.addSlider("Bulk Viscosity",	"BULK_VISCOSITY",	3.0,	0, 10.0,	false);
	gui.addSlider("Elasticity",		"ELASTICITY",		1.0,	0, 4.0,		false);
    gui.setWhichColumn(2);
	gui.addSlider("Viscosity",		"VISCOSITY",		1.0,	0, 4.0,		false);
	gui.addSlider("Yield Rate",		"YIELD_RATE",		1.0,	0, 2.0,		false);
    gui.setWhichColumn(3);
	gui.addSlider("Gravity",		"GRAVITY",			0.0,	0, 0.02,	false);
	gui.addSlider("Smoothing",		"SMOOTHING",		1.0,	0, 3.0,		false);

    hascontrols = true;
}

//--------------------------------------------------------------
void testApp::update(){

	fluid.densitySetting = gui.getValueF("DENSITY", 0);
	fluid.stiffness      = gui.getValueF("STIFFNESS", 0);
	fluid.bulkViscosity  = gui.getValueF("BULK_VISCOSITY", 0);
	fluid.elasticity     = gui.getValueF("ELASTICITY", 0);
	fluid.viscosity      = gui.getValueF("VISCOSITY", 0);
	fluid.yieldRate      = gui.getValueF("YIELD_RATE", 0);
	fluid.gravity		 = gui.getValueF("GRAVITY", 0);
	fluid.smoothing		 = gui.getValueF("SMOOTHING", 0);
    
    fluid.scaleFactor = scaleFactor;
    fluid.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	fluid.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key=='r'){                      // reset
        fluid.reset();
    }
    else if (key == 'f'){               // fullscreen
		isfullscreen = !isfullscreen;
		ofSetFullscreen(isfullscreen);
        scaleFactor = (float)ofGetWindowWidth() / (float)fluid.getGridSizeX();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
