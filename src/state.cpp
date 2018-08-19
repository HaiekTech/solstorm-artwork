//
//  state.cpp
//  solstorm-artwork-clean
//
//  Created by Kristoffer Lundberg on 19/08/2018.
//

#include "state.hpp"

void State::init() {
    cout << "hello" << endl;
}

void State::calculate() {
    
    nudge1 = 0.04;
    nudge2 = 0.04;
    nudge3 = 0.005;
    
    nudgePower1 = ofRandom(6);
    nudgePower2 = ofRandom(6);
    nudgePower3 = 32;
    
    float calculatedGutter = canvasWidth * gutter.get();
    float calculatedSideMargin = (canvasWidth * minimumSideMargin.get()) * 2;
    
    float availableSpace = canvasWidth - calculatedSideMargin - calculatedGutter;
    
    // calculate right box
    float rightBoxWidth = availableSpace * boxWidthDifference.get();
    float rightBoxHeight = canvasHeight.get() * boxHeight.get();
    float rightBoxX = (availableSpace/2) - rightBoxWidth;
    
    rightBox = ofRectangle(rightBoxX + (calculatedGutter/2), rightBoxHeight/2*-1, rightBoxWidth, rightBoxHeight);
    
    // calculate anchors
    float randomX = ofRandom(1.0f);
    float randomY = ofRandom(0.5f);
    randomY = 1.0f - randomY;
    
    float c2Edge1 = 1.0f;
    float c2Edge2 = 1.0f;
    
    if ((int)ofRandom(2) == 1) {
        c2Edge1 = 0.0f;
        c2Edge2 = 1.0f;
    }
    else {
        c2Edge1 = 1.0f;
        c2Edge2 = 0.0f;
    }
    
    rightBoxAnchor1 = ofVec2f( rightBox.x + ((rightBox.width * 0.45)*c2Edge1) * randomX, rightBox.y + ((rightBox.height/2) * randomY) );
    
    randomX = ofRandom(1.0f);
    randomY = ofRandom(0.5f);
    randomY = 1.0f - randomY;
    
    rightBoxAnchor2 = ofVec2f( rightBox.x + ((rightBox.width * 0.45)*c2Edge2) * randomX, rightBox.y + (rightBox.height * randomY) );
    
    // calculate left box
    float remainingWidthPct = 1.0f - boxWidthDifference.get();
    float leftBoxWidth = availableSpace * remainingWidthPct;
    float leftBoxHeight = rightBoxHeight;
    float leftBoxX = rightBox.x - leftBoxWidth - calculatedGutter - (calculatedSideMargin/2);
    
    leftBox = ofRectangle(leftBoxX + (calculatedSideMargin/2), leftBoxHeight/2*-1, leftBoxWidth, leftBoxHeight);
    
    calculateRightShape();
}

void State::calculateRightShape() {
    
    float a = rightBoxAnchor1.x - rightBoxAnchor1.x;
    float b = rightBox.y - rightBoxAnchor1.y;
    int anchor1Dist = (int)ceil( sqrt(a*a + b*b) );
    
    float nudge = 0.0f;
    float offset = 0.0;
    
    anchor1Array.clear();
    for (int i = 0; i < anchor1Dist; i++) {
        nudge += nudge1;
        offset = ofNoise(nudge) * nudgePower1;
        
        anchor1Array.push_back(ofVec2f(rightBoxAnchor1.x + offset, rightBox.y + i));
    }
    
    float realAnchor1X = rightBoxAnchor1.x + offset; // after noise offset
    
    a = realAnchor1X - rightBoxAnchor2.x;
    b = rightBoxAnchor1.y - rightBoxAnchor2.y;
    int anchor2Dist = (int)ceil( sqrt(a*a + b*b) );
    
    nudge = 0;
    anchor2Array.clear();
    for (int i = 0; i < anchor2Dist; i++) {
        nudge += nudge2;
        offset = ofNoise(nudge) * nudgePower2;
        
        float _x = ofMap(i, 0, anchor2Dist, realAnchor1X, rightBoxAnchor2.x);
        float _y = ofMap(i, 0, anchor2Dist,rightBoxAnchor1.y, rightBoxAnchor2.y);
        
        anchor2Array.push_back( ofVec2f(_x + offset, _y) );
    }
    
    float realAnchor2X = rightBoxAnchor2.x + offset; // after noise offset
    a = realAnchor2X - realAnchor2X;
    b = rightBoxAnchor2.y - (rightBox.height/2);
    int stepsToFinish = (int)ceil( sqrt(a*a + b*b) );
    
    anchor3Array.clear();
    for (int i = 0; i < stepsToFinish; i++) {
        anchor3Array.push_back( ofVec2f(realAnchor2X, rightBoxAnchor2.y + i) );
    }
    
    a = realAnchor2X - (rightBox.x + rightBox.width);
    b = 0;
    stepsToFinish = (int)ceil( sqrt(a*a + b*b) );
    
    nudge = 0;
    anchor4Array.clear();
    for (int i = 0; i < stepsToFinish; i++) {
        float realoffset = 0.0f;
        
        if (i < stepsToFinish * 0.8) {
            nudge += nudge3;
            offset = ofNoise(nudge) * nudgePower3;
            realoffset = offset;
        }
        else {
            realoffset = 0;
        }
        
        anchor4Array.push_back( ofVec2f(realAnchor2X + i, rightBox.height/2) );
    }

}

void State::draw() {
    ofNoFill();
    ofSetLineWidth(2.0f);
    ofSetColor(0, 0, 0, 50);
    
    if (showWireframes) {
        // draw contours of the two boxes
        ofDrawRectangle(leftBox.x, leftBox.y, leftBox.width, leftBox.height);
        ofDrawRectangle(rightBox.x, rightBox.y, rightBox.width, rightBox.height);
    }
    
    // start drawing the real shape of the right box
    ofFill();
    ofSetColor(0, 0, 0);
    ofBeginShape();
    
    ofVertex(rightBox.x + rightBox.width, rightBox.height/2); // bottom right
    ofVertex(rightBox.x + rightBox.width, rightBox.y); // top right
    ofVertex(rightBoxAnchor1.x, rightBox.y); // top left
    
    for (int i = 0; i < anchor1Array.size(); i++) {
        ofVertex(anchor1Array[i]);
    }
    
    for (int i = 0; i < anchor2Array.size(); i++) {
        ofVertex(anchor2Array[i]);
    }
    
    for (int i = 0; i < anchor3Array.size(); i++) {
        ofVertex(anchor3Array[i]);
    }
    
    for (int i = 0; i < anchor4Array.size(); i++) {
        ofVertex(anchor4Array[i]);
    }
    
    ofEndShape();
    
    if (showWireframes) {
        // show anchors
        ofSetColor(0, 0, 0);
        ofDrawEllipse(rightBoxAnchor1.x, rightBoxAnchor1.y, 10, 10);
        ofDrawEllipse(rightBoxAnchor2.x, rightBoxAnchor2.y, 10, 10);
    }

}
