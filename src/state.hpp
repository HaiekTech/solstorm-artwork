//
//  state.hpp
//  solstorm-artwork-clean
//
//  Created by Kristoffer Lundberg on 19/08/2018.
//

#include "ofMain.h"

#ifndef state_h
#define state_h

class State {
    
public:
    
    void init();
    void calculate();
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
    
    bool showWireframes = true;
    
};

#endif /* state_h */
