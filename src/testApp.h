#pragma once

#include "ofMain.h"
#include "ofxCsv.h"
#include "ofxMPMFluid.h"
#include "ofxAutoControlPanel.h"  /* for the control panel */

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    private:
        float scaleFactor;
        bool hascontrols = false;
        bool  isfullscreen = false;
    
        wng::ofxCsv csv;
        ofxMPMFluid fluid;
        vector<ofxMPMParticle*> particles;
    
        ofxAutoControlPanel gui;
        void setupControlPanel();
};
