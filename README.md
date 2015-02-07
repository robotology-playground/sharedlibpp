
Simple cross platform plug-in system 
====================================

The sharedlibpp is a tiny cross-platform library to create and load shared 
libraries for different platform (Linux/Mac/Windows). The sharedlibpp provide
an easy and portable way to create plug-ins which encapsulate your c++ classes
inside a shared library (so, dylib, dll). The original code is taken and from 
[YARP](http://wiki.icub.org/yarpdoc/index.html) (Yet Another Robot Platform). 
The code is simplified by removing dependencies and some helper functions are added 
to report the native OS error messages on failures. 


Building on Linux/Mac
---------------------
    $ cd sharedlibpp
    $ mkdir build; cd build
    $ cmake ../; make 


Building on Windows
-------------------
The easiest way is to use Cmake to create VStudio project. To do that: 

* download and install [cmake](http://www.cmake.org/download/) for windows.
* open the cmake gui and set the source path to `sharedlibpp` and set the
  build path (for exmaple `sharedlibpp/build`).
* configure and generate visual studio project. 
* open the project and built it. 

Running exmaple
----------------
The build system by defualt compiles and build the examples. 

* On Linux/Mac
```
    $ cd sharedlibpp/build/examples
    $ ./math_test libmymath.so
```
* On Windows first switch to directory where example is created and then 
```
    > math_test math.dll
```

## Co-author and development lead

- Ali Paikan (ali.paikan@gmail.com)


## Original author

- Paul Fitzpatrick 

