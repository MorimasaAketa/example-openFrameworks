perfume-bvh-oF
======================

This is a Perfume-dev #001's fork.

I updated project settings and modified some code 
to work with openFrameworks v0.11.2 in XCode 13.1 and macOS 10.15, or in Windows and Visual Studio 2017.	

As all projects contains VS2017 project setting files, you can build on windows immediately except for 'marchin-cubes' example.

Data files containg in bin/data.

# Basic setup steps for OS X

1. Install XCode.
2. Download openFrameworks 0.11.2 or later from [official site](http://openframeworks.cc/download/) .
3. Clone or "download zip" and extract this repository to folder `of_0.11.2_osx_release/apps/`. 
4. Copy ofx* folders ( ofxBvh, ofxMarchingCubes, ofxSTL ) from `of_0.11.2_osx_release/apps/perfume-bvh-oF` to `of_0.11.2_osx_release/addons/` .
5. Open `example-bvh/example-bvh.xcodeproj` and build.

# Basic setup steps for Windows/Visual Studio 2017

1. Install Visual Studio Community 2015 with C++ component.
2. Download openFrameworks 0.11.2 or later for Visual Studio 2017 from [official site](http://openframeworks.cc/download/) .
3. Clone or "download zip" and extract this repository to folder `of_0.11.2_vs_release/apps/`. 
4. Copy ofxBvh folder from `of_0.11.2_vs_release/apps/perfume-bvh-oF/` to `of_0.11.2_vs_release/addons/` .
5. Open `example-bvh/example-bvh.sln` . and push 'Local Windows Debugger' button.


