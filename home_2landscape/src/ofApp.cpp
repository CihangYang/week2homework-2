#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load( "shaderVert.c", "shaderFrag.c" );
    
    fbo.allocate( ofGetWidth(), ofGetHeight() );
    image.loadImage( "cloud1.png" );
    image1.loadImage( "cloud2.png" );
    image2.loadImage( "cloud3.png" );
    
    mult = 0.012;
    noisePixels.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);


}

//--------------------------------------------------------------
void ofApp::update(){
    for (int y = 0;y < ofGetHeight(); y++) {
        for (int x = 0; x < ofGetWidth(); x++) {
            ofFloatColor color = ofFloatColor(ofNoise(x*mult, y*mult));
            noisePixels.setColor(x, y, color);
        }
    }
    
    noiseImg.setFromPixels(noisePixels.getPixels(), noisePixels.getWidth(), noisePixels.getHeight(), OF_IMAGE_COLOR);


}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();	
    
  
    ofSetColor(255,255,255);
    noiseImg.draw(0, 0);
    

    ofSetColor( 255, 255, 255 );
    image.draw( 50, 15,300,300 );
    
    ofSetColor( 255, 255, 255 );
    image1.draw(400, 30,170,170 );
    
    ofSetColor( 255, 255, 255 );
    image2.draw(200, 0,500,500 );
    
    
    ofSetColor( 255, 255, 255 );
    image2.draw(540, 0,400,400 );
    
    ofSetColor( 255, 255, 255 );
    image.draw( 50, 70,300,300 );
    
    ofSetColor( 255, 255, 255 );
    image1.draw(400, 70,170,170 );
    
    ofSetColor( 255, 255, 255 );
    image2.draw(200, 70,500,500 );
    
    
    ofSetColor( 255, 255, 255 );
    image2.draw(540, 90,400,400 );
    
    fbo.end();
        shader.begin();
    
    float time = ofGetElapsedTimef();
    shader.setUniform1f( "time", time );
  
    ofSetColor( 255, 255, 255 );
    fbo.draw( 0, 0 );
    
    shader.end();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
