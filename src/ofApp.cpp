#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    state.init();
    
    gui.setup("panel");
    
    state.canvasWidth.addListener(this, &ofApp::canvasWidthChanged);
    gui.add(state.canvasWidth.set("width", 1800, 400, 2600));
    
    state.canvasHeight.addListener(this, &ofApp::canvasHeightChanged);
    gui.add(state.canvasHeight.set("height", 1800, 400, 1800));
    
    state.minimumSideMargin.addListener(this, &ofApp::minimumSideMarginChanged);
    gui.add(state.minimumSideMargin.set("min. margin", 0.06, 0.0f, 0.4f));
    
    state.gutter.addListener(this, &ofApp::minimumGutterChanged);
    gui.add(state.gutter.set("gutter", 0.0055f, 0.0f, 0.22f));
    
    state.boxWidthDifference.addListener(this, &ofApp::boxWidthDifferenceChanged);
    gui.add(state.boxWidthDifference.set("box width diff", 0.4, 0.2, 0.8));
    
    state.calculate();
}

//--------------------------------------------------------------
void ofApp::minimumSideMarginChanged(float & val) {
    state.minimumSideMargin = val;
    state.calculate();
}

//--------------------------------------------------------------
void ofApp::minimumGutterChanged(float & val) {
    state.gutter = val;
    state.calculate();
}

//--------------------------------------------------------------
void ofApp::boxWidthDifferenceChanged(float & val) {
    state.boxWidthDifference = val;
    state.calculate();
}

//--------------------------------------------------------------
void ofApp::canvasWidthChanged(float & val) {
    state.canvasWidth = val;
    state.calculate();
}

//--------------------------------------------------------------
void ofApp::canvasHeightChanged(float & val) {
    state.canvasHeight = val;
    state.calculate();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    
    int cw = state.canvasWidth.get()  / 2;
    int ch = state.canvasHeight.get() / 2;
    
    gui.draw();
    
    ofSetBackgroundColor(140, 140, 140);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
        ofNoFill();
        ofSetColor(0, 0, 0);
        ofSetLineWidth(1.0f);
    
        ofDrawRectangle(cw*-1, ch*-1, cw*2, ch*2);
    
        state.draw();
    
    ofPopMatrix();
    
    drawGuides();
    
}

void ofApp::drawGuides() {
    int cw = state.canvasWidth.get()  / 2;
    int ch = state.canvasHeight.get() / 2;
    
    ofSetColor(0);
    ofSetLineWidth(1.0f);
    ofDrawLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    ofDrawLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofNoFill();
    
    // x
    ofDrawBitmapString(ofToString(cw*-1), cw*-1, 0);
    ofDrawBitmapString(ofToString(cw), cw-30, 0);
    
    // 0
    ofDrawBitmapString("0", -5, 4);
    
    // y
    ofDrawBitmapString(ofToString(ch*-1), -20, (ch*-1)+10);
    ofDrawBitmapString(ofToString(ch), -15, ch);
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
