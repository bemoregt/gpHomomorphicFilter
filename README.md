# ofxHomomorphicF
Spatial Domain Homomorphic Filter for Openframeworks using ofxCv

![HMF example]( https://github.com/bemoregt/ofxHomomorphicF/blob/master/ScrShot%2012.png "HMF")

![HMF example2]( https://github.com/bemoregt/ofxHomomorphicF/blob/master/ScrShot%2013.png "HMF2")

### Algorithm
- Homomorphic Filter is a kind of Cepstral Technics of image.
- Ambient light has Low frequency information. But, Object light has Higher frequency info. 
- Logarithmic of Power spectrum is separate two above informations and Low Stop Filtering.


### How To
- Move your mouse horizontally to change Alpha param in realtime. 
- Move your mouse verticallyl to change Beta param in realtime. 

### Dependency
- OpenFrameworks 0.10.1
- ofxCv
- ofxOpenCv
- ofxGUI
- XCode 10.12.x
- OSX Mojave

### Next Plan
- FFT based Homomorphic Filtering
- Realtime WebCam Homomorphic Filtering

### Reference
- Porting of this source: https://stackoverflow.com/questions/23740934/opencv-homomorphic-filter
