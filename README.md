CMakeCatchMPI
------------------

[![Build Status](https://travis-ci.com/MattClarkson/CMakeCatchMPI.svg?branch=master)](https://travis-ci.com/MattClarkson/CMakeCatchMPI)


Purpose
-------

This is a demo project to demonstrate a reasonable structure for [CMake](https://cmake.org/) based projects,
that use [CTest](https://cmake.org/) to run unit tests via [Catch](https://github.com/catchorg/Catch2),
specifically demonstrating some uses of MPI.


Credits
-------

This project was developed as a teaching aid for UCL's ["Research Computing with C++"](http://rits.github-pages.ucl.ac.uk/research-computing-with-cpp/)
course developed by [Dr. James Hetherington](http://www.ucl.ac.uk/research-it-services/people/james)
and [Dr. Matt Clarkson](https://iris.ucl.ac.uk/iris/browse/profile?upi=MJCLA42).


Build Instructions
------------------

On Linux/Mac, in a terminal:
``` cmake
git clone https://github.com/MattClarkson/CMakeCatchMPI
mkdir CMakeCatchMPI-Build
cd CMakeCatchMPI-Build
cmake ../CMakeCatchMPI
make
```
On Windows, run the CMake GUI to generate Visual Studio project files, and run the build therein.

