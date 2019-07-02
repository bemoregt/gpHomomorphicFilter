#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::setup(){
    
    alpha =0.5;
    beta =1.5;
    // load
    filePath= "/Users/kerbal/Desktop/beforec.png";
    before.load(filePath);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    // ofImage to Mat
    Mat imgSrcM= toCv(before);
    Mat imgDstM;
    
    Mat imgGray;
    Mat imgHls;
    vector<Mat> vHls;
    
    Mat imgTemp1=Mat::zeros(imgSrcM.size(),CV_64FC1);
    Mat imgTemp2=Mat::zeros(imgSrcM.size(),CV_64FC1);
    
    // Make Gray
    if(imgSrcM.channels()==1)
    {
        imgGray=imgSrcM.clone();
    }
    else if (imgSrcM.channels()==3)
    {
        cvtColor(imgSrcM, imgHls, CV_BGR2HLS);
        split(imgHls, vHls);
        imgGray=vHls.at(1);
    }
    else
    {
        return -1;
    }
    // int to float
    imgGray.convertTo(imgTemp1,CV_64FC1);
    // ??
    imgTemp1 = imgTemp1+0.0001;
    // logarithmic
    log(imgTemp1,imgTemp1);
    // smoothing
    GaussianBlur(imgTemp1, imgTemp2, cv::Size(21, 21), 0.1, 0.1, BORDER_DEFAULT);// Low pass filtering
    imgTemp1 = (imgTemp1 - imgTemp2);//imgTemp1
    addWeighted(imgTemp2, alpha, imgTemp1, beta, 1, imgTemp1, -1);// Low Stop Filtering
    
    exp(imgTemp1,imgTemp1);
    // normalize
    normalize(imgTemp1,imgTemp1,0,1,NORM_MINMAX);
    imgTemp1=imgTemp1*255;
    
    imgTemp1.convertTo(imgGray, CV_8UC1);
    
    if (imgSrcM.channels()==3)
    {
        vHls.at(1)=imgGray;
        merge(vHls,imgHls);
        cvtColor(imgHls, imgDstM, CV_HLS2BGR);
        
    }
    else if (imgSrcM.channels()==1)
    {
        imgDstM=imgGray.clone();
    }
    
    toOf(imgDstM, after);
    after.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // images
    ofSetColor(255, 255, 255);
    before.draw(0, 0, 512, 512);
    after.draw(512, 0, 512, 512);
    
    // text box
    // filled box
    ofSetColor(100, 100, 100);
    ofDrawRectangle(5, 5, 200, 60);
    
    // text
    ofSetColor(255);
    ofDrawBitmapString("Alpha= " + ofToString(alpha), 20, 30);
    ofDrawBitmapString("Beta= " + ofToString(beta), 20, 50);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    alpha = x/1024.0;
    if (alpha <0.1){
        alpha=0.1;
    }
    if (alpha >0.99){
        alpha= 0.99;
    }
    
    beta = y/512.0*1.5;
    if (beta < 0.1){
        beta=0.1;
    }
    if (beta > 1.99){
        beta= 1.99;
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
