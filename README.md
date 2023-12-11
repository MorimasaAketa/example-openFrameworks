perfume-bvh-oF
======================

This is a Perfume-dev #001's fork.

I updated project settings and modified some code 0.12.0 in XCode 14.3 and macOS 13.4, or in Windows and Visual Studio 2019.	

As all projects contains VS2017 project setting files, you can build on windows immediately except for 'marchin-cubes' example.

Data files containg in bin/data.

# Basic setup steps for OS X

1. Install XCode.
2. Download openFrameworks 0.12.0 or later from [official site](http://openframeworks.cc/download/) .
3. Clone or "download zip" and extract this repository to folder `of_0.12.0_osx_release/apps/`. 
4. Copy ofx* folders ( ofxBvh, ofxMarchingCubes, ofxSTL ) from `of_0.12.0_osx_release/apps/perfume-bvh-oF` to `of_0.12.0_osx_release/addons/` .
5. Open `example-bvh/example-bvh.xcodeproj` and build.

# Basic setup steps for Windows/Visual Studio 2019

1. Install Visual Studio Community 2019 with C++ component.
2. Download openFrameworks 0.12.0 or later for Visual Studio 2019 from [official site](http://openframeworks.cc/download/) .
3. Clone or "download zip" and extract this repository to folder `of_0.12.0_vs_release/apps/`. 
4. Copy ofx* folders ( ofxBvh, ofxMarchingCubes, ofxSTL ) from `of_0.12.0_vs_release/apps/perfume-bvh-oF/` to `of_0.12.0_vs_release/addons/` .
5. Open `example-bvh/example-bvh.sln` . and push 'Local Windows Debugger' button.


