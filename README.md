perfume-bvh-oF
======================

This is a Perfume-dev #001's fork.

I updated project settings and modified some code 
to work with openFrameworks v0.9.x in XCode 8.2 and macOS 10.12, or in Windows and Visual Studio 2015.	

As all projects contains VS2015 project setting files, you can build on windows immediately except for 'marchin-cubes' example.

You need to download Perfume's real motion capture data and sound file from perfume-global site in order to build and execute except for `example-bvh`. 

http://perfume-global.com/visualization.html


When you lay cursor on upper left of the page, you will find the 'DOWNLOAD' link to data.

Real motion capture data, .bvh files should be placed in bin/data/bvhfiles of each project directory.

Sound file, .wav file shoud be placed in bin/data directory.

Only `example-bvh` does not need other data, it is independent project.

# Basic setup steps for OS X

1. Install XCode.
2. Download openFrameworks 0.9.8 or later from [official site](http://openframeworks.cc/download/) .
3. Clone or "download zip" and extract this repository to folder `of_0.9.8_osx_release/apps/`. 
4. Copy ofx* folders ( ofxBvh, ofxMarchingCubes, ofxSTL ) from `of_0.9.8_osx_release/apps/perfume-bvh-oF` to `of_0.9.8_osx_release/addons/` .
5. Open `example-bvh/example-bvh.xcodeproj` and build.

# Basic setup steps for Windows/Visual Studio 2015

1. Install Visual Studio Community 2015 with C++ component.
2. Download openFrameworks 0.9.8 or later for Visual Studio from [official site](http://openframeworks.cc/download/) .
3. Clone or "download zip" and extract this repository to folder `of_0.9.8_vs_release/apps/`. 
4. Copy ofxBvh folder from `of_0.9.8_vs_release/apps/perfume-bvh-oF/` to `of_0.9.8_vs_release/addons/` .
5. Open `example-bvh/example-bvh.sln` . and push 'Local Windows Debugger' button.


