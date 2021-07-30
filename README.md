# CMake Template GCC

CMake template using GCC/MinGW, with many levels of abstraction.

## Building on Linux

1. Clone repository: `git clone https://github.com/brunowinkeler/cmake-template-gcc.git` 
2. Dependencies:
    * CMake: 3.10+
    * GCC
    * Make
3. Create a 'build' folder
4. From 'build' folder run:
    * `cmake ..`
    * `make`
    * `make install`
5. Run exec file: `./ExecCmakeTemplate`

## Building on Windows

1. Clone repository: `git clone https://github.com/brunowinkeler/cmake-template-gcc.git` 
2. Dependencies:
    * CMake: 3.10+
    * MinGW (Set bin folder to `PATH`)
3. Create a 'build' folder
4. From 'build' folder run:
    * `cmake .. -G "MinGW Makefiles"`
    * `mingw32-make.exe`
    * `mingw32-make.exe install`
5. Run exec file: `./ExecCmakeTemplate`