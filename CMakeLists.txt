# Defines the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project Name
set(PROJ_NAME cmake-template-gcc)
set(EXEC_NAME ExecCmakeTemplate)

project(${PROJ_NAME})

set(PROJECT_SOURCES         ${CMAKE_SOURCE_DIR}/src)
set(PROJECT_INCLUDES        ${CMAKE_SOURCE_DIR}/include)

include_directories(${PROJECT_INCLUDES})

# Set CMAKE_INSTALL_PREFIX to define install directory
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "Default Install Path" FORCE)

# Collect sources into the variable
file(GLOB SANDBOX_SOURCES
        "src/*.c"
        "src/*.cpp"
)

add_executable(${EXEC_NAME} ${SANDBOX_SOURCES})

# Define installation folders
set(PROJECT_BINARIES    "${CMAKE_INSTALL_PREFIX}/bin")
install(TARGETS ${EXEC_NAME} 
        RUNTIME DESTINATION ${PROJECT_BINARIES}
)