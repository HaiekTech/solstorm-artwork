//
//  state.hpp
//  solstorm-artwork-clean
//
//  Created by Kristoffer Lundberg on 19/08/2018.
//

#ifndef state_h
#define state_h

#include "ofMain.h"
#include "dot.hpp"

class State {
    
public:
    
    void init();
    void calculate();
    void calculateRightShape();
    void distributeDots();
    void draw();
    
    float nudge1;
    float nudge2;
    float nudge3;
    
    float nudgePower1;
    float nudgePower2;
    float nudgePower3;
    
    ofRectangle leftBox;
    ofRectangle rightBox;
    
    ofVec2f rightBoxAnchor1;
    ofVec2f rightBoxAnchor2;
    
    ofParameter<float> canvasWidth;
    ofParameter<float> canvasHeight;
    ofParameter<float> boxHeight;
    
    ofParameter<float> boxWidthDifference;
    ofParameter<float> minimumSideMargin;
    ofParameter<float> gutter;
    
    vector<ofVec2f> anchor1Array;
    vector<ofVec2f> anchor2Array;
    vector<ofVec2f> anchor3Array;
    vector<ofVec2f> anchor4Array;
    
    vector<Dot> dotArray;
    
    bool showWireframes = true;
    
};

#endif /* state_h */
