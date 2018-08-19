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
    
    // calculate right box
    float rightBoxWidth = availableSpace * boxWidthDifference.get();
    float rightBoxHeight = canvasHeight.get() * boxHeight.get();
    float rightBoxX = (availableSpace/2) - rightBoxWidth;
    
    rightBox = ofRectangle(rightBoxX + (calculatedGutter/2), rightBoxHeight/2*-1, rightBoxWidth, rightBoxHeight);
    
    // calculate anchors
    float randomX = ofRandom(1.0f);
    float randomY = ofRandom(0.5f);
    randomY = 1.0f - randomY;
    
    rightBoxAnchor1 = ofVec2f( rightBox.x + (rightBox.width * 0.45) * randomX, rightBox.y + (rightBox.height * randomY) );
    
    randomX = ofRandom(1.0f);
    randomY = ofRandom(0.5f);
    randomY = 1.0f - randomY;
    rightBoxAnchor2 = ofVec2f( rightBox.x + (rightBox.width * 0.45) * randomX, rightBox.y + ((rightBox.height/2) * randomY) );
    
    // calculate left box
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
    
    ofSetColor(255, 0, 0);
    // right box, right side
    ofDrawLine(rightBox.x + rightBox.width, rightBox.y, rightBox.x + rightBox.width, rightBox.height/2);
    
    ofFill();
    ofSetColor(0, 0, 0);
    ofDrawEllipse(rightBoxAnchor1.x, rightBoxAnchor1.y, 10, 10);
    ofDrawEllipse(rightBoxAnchor2.x, rightBoxAnchor2.y, 10, 10);
}
