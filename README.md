CMakeCatchMPI
------------------

[![Build Status](https://travis-ci.org/MattClarkson/CMakeCatchMPI.svg?branch=master)](https://travis-ci.org/MattClarkson/CMakeCatchMPI)


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

This project itself can be built if you just want to test it. In Linux terms that
would be:
``` cmake
git clone https://github.com/MattClarkson/CMakeCatchMPI
mkdir CMakeCatchMPI-Build
cd CMakeCatchMPI-Build
cmake ../CMakeCatchMPI
make
```
But ideally, you should use this as a template to create your own project. To do so,
please refer to the [CMakeTemplateRenamer](https://github.com/MattClarkson/CMakeTemplateRenamer)
which will show you how to clone this repository, and rename all the variables to names of your choice.
Then you would simply build your new project, using cmake, as shown above.
