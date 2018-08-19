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
    float calculatedGutter = canvasWidth * gutter.get();
    float calculatedSideMargin = (canvasWidth * minimumSideMargin.get()) * 2;
    
    float availableSpace = canvasWidth - calculatedSideMargin - calculatedGutter;
    
    float rightBoxWidth = availableSpace * boxWidthDifference.get();
    float rightBoxHeight = canvasHeight.get() * 0.75;
    float rightBoxX = (availableSpace/2) - rightBoxWidth;
    
    rightBox = ofRectangle(rightBoxX + (calculatedGutter/2), rightBoxHeight/2*-1, rightBoxWidth, rightBoxHeight);
    
    float remainingWidthPct = 1.0f - boxWidthDifference.get();
    float leftBoxWidth = availableSpace * remainingWidthPct;
    float leftBoxHeight = rightBoxHeight;
    float leftBoxX = rightBox.x - leftBoxWidth - calculatedGutter - (calculatedSideMargin/2);
    
    leftBox = ofRectangle(leftBoxX + (calculatedSideMargin/2), leftBoxHeight/2*-1, leftBoxWidth, leftBoxHeight);
}

void State::draw() {
    ofNoFill();
    ofSetLineWidth(2.0f);
    ofSetColor(0, 0, 0);
    
    ofDrawRectangle(leftBox.x, leftBox.y, leftBox.width, leftBox.height);
    ofDrawRectangle(rightBox.x, rightBox.y, rightBox.width, rightBox.height);
}
