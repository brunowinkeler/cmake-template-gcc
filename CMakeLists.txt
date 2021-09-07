# Defines the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project Name
set(PROJ_NAME cmake-template-gcc)

# Creation of project with call of toolchain
project(${PROJ_NAME})

# Set CMAKE_INSTALL_PREFIX to define install directory
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "Default Install Path" FORCE)

# Set "Debug" as default build type
if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Debug")
    message(STATUS "Library will be built in \"${CMAKE_BUILD_TYPE}\" mode")
endif()

# Set Lib's name and type
set(LIBRARY_NAME   tests)
# To make static just replace SHARED by STATIC
set(LIBRARY_TYPE   SHARED)

# Set of Local Variables for location
set(PROJECT_SOURCES         ${CMAKE_SOURCE_DIR}/src)
set(PROJECT_INCLUDES        ${CMAKE_SOURCE_DIR}/include)

# Define the folder of Includes, libraries and Runtime Files. (.h, .hpp, .ilk, .exe, .dll, .lib, .exp etc.)
set(LIBRARY_BINARIES        lib${LIBRARY_NAME}/bin)
set(LIBRARY_LIBRARIES       lib${LIBRARY_NAME}/lib)
set(LIBRARY_INCLUDES        lib${LIBRARY_NAME}/include)

set(INSTALL_LIBRARY_BINARIES        ${CMAKE_INSTALL_PREFIX}/${LIBRARY_BINARIES})
set(INSTALL_LIBRARY_LIBRARIES       ${CMAKE_INSTALL_PREFIX}/${LIBRARY_LIBRARIES})
set(INSTALL_LIBRARY_INCLUDES        ${CMAKE_INSTALL_PREFIX}/${LIBRARY_INCLUDES})

# Add project's modules
add_subdirectory(src)
