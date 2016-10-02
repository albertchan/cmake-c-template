# cmake-c-template

This repository provides a non-trivial example of setting up a C99 project 
using the CMake cross-platform compiler.

The project structure is provided below:

```
.
├── bin/                                # Folder for built application binary
├── include/                            # Dependencies
├── src/                                # Folder for all source files
│   └── main.c                          # Main entry of the application
├── test/                               # Test folder for all unit tests
│   └── CMakeLists.txt                  # Compile script for unit tests
└── CMakeLists.txt                      # Main compile script
```

## Dependencies

This project was built and tested on the Mac OS X platform with the
following dependencies:

* CMake >= 3.5

## Instructions

Do as you would any CMake project to compile:

```
mkdir cmake
cd cmake
cmake ..
make
```

Run application:

```
cd bin
./cmake_c_template
```

Run unit test suite:

```
cd cmake/test
ctest
```

## References

* [CMake: An introduction](https://www.cs.swarthmore.edu/~adanner/tips/cmake.php)
* [CMake/Testing with CTest](https://cmake.org/Wiki/CMake/Testing_With_CTest)
