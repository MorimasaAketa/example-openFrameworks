perfume-bvh-oF
======================

This is a Perfume-dev #001's fork.

I Updated project settings and modified some code 
to work with openFrameworks v0.9.x in XCode 7.2, OS X 10.10.

Some projects contains VS2012 project files.

You need to download real Perfume motion capture data and sound file from perfume-global site.

http://perfume-global.com/visualization.html

When you lay cursor on upper left of the page, you will find the 'DOWNLOAD' link to data.

Real motion capture data, .bvh files should be placed in bin/data/bvhfiles of each project directory.

Sound file, .wav file shoud be placed in bin/data directory.

# Basic setup for OS X

1. Install XCode.
2. Download openFrameworks 0.9.8 or later from [official site](http://openframeworks.cc/download/) .
3. Clone or "download zip" and extract this repository to folder `oF_0.9.8_osx_release/apps/`. 
4. Copy ofx* folders ( ofxBvh, ofxMarchingCubes, ofxSTL ) from `oF_0.9.8_osx_release/apps/perfume-bvh-oF` to `oF_0.9.8_osx_release/addons/` .
5. open `example-bvh/example-bvh.xcodeproj` and build.

