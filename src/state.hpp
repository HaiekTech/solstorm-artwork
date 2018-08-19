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
    
    ofParameter<int> canvasWidth;
    ofParameter<int> canvasHeight;
    
    ofParameter<int> boxWidthDifference;
    ofParameter<float> minimumSideMargin;
    ofParameter<float> gutter;
    
};

#endif /* state_h */
