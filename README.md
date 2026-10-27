# customVector

An educational C++ project implementing a custom dynamic array class.

## Features

- Dynamic array implementation
- Copy constructor and copy assignment operator
- Overloaded `[]`, `==`, and `!=` operators
- Exception handling for error conditions
- Parameterized and capacity-based construction

## Technologies

- C++20
- Object-Oriented Programming (OOP)
- CMake

## Project Structure

- `main.cpp` — program entry point
- `menuOfVector.cpp` / `menuOfVector.h` — vector-related functionality and menu

## Build

Make sure you have a C++ compiler and CMake 3.10 or later installed.

Run these commands from the project root directory:

```bash
cmake -S . -B build
cmake --build build
```

## Run

On Windows, the executable is typically located at:

```bash
build/Debug/customVector.exe
```

or, depending on the CMake generator and build configuration:

```bash
build/customVector.exe
```

On Linux:

```bash
./build/customVector
```

## Purpose

This project demonstrates fundamental C++ concepts, including class design, operator overloading, object copying, exception handling, and dynamic data structures.
