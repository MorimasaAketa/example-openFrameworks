perfume-bvh-oF
======================

This is a Perfume-dev #001's fork.

I updated project settings and modified some code 
to work with openFrameworks v0.10.1 in XCode 10 and macOS 10.13, or in Windows and Visual Studio 2017.	

As all projects contains VS2017 project setting files, you can build on windows immediately except for 'marchin-cubes' example.

Data files containg in bin/data.

# Basic setup steps for OS X

1. Install XCode.
2. Download openFrameworks 0.9.8 or later from [official site](http://openframeworks.cc/download/) .
3. Clone or "download zip" and extract this repository to folder `of_0.10.1_osx_release/apps/`. 
4. Copy ofx* folders ( ofxBvh, ofxMarchingCubes, ofxSTL ) from `of_0.10.1_osx_release/apps/perfume-bvh-oF` to `of_0.10.1_osx_release/addons/` .
5. Open `example-bvh/example-bvh.xcodeproj` and build.

# Basic setup steps for Windows/Visual Studio 2015

1. Install Visual Studio Community 2015 with C++ component.
2. Download openFrameworks 0.9.8 or later for Visual Studio from [official site](http://openframeworks.cc/download/) .
3. Clone or "download zip" and extract this repository to folder `of_0.10.1_vs_release/apps/`. 
4. Copy ofxBvh folder from `of_0.10.1_vs_release/apps/perfume-bvh-oF/` to `of_0.10.1_vs_release/addons/` .
5. Open `example-bvh/example-bvh.sln` . and push 'Local Windows Debugger' button.


