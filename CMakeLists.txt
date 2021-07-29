# Defines the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project Name
set(PROJ_NAME cmake-template-gcc)
set(EXEC_NAME ExecCmakeTemplate)

project(${PROJ_NAME})

# Set CMAKE_INSTALL_PREFIX to define install directory
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "Default Install Path" FORCE)

# Collect sources into the variable
file(GLOB SANDBOX_SOURCES
        "main.cpp"
        "tests.cpp"
)

add_executable(${EXEC_NAME} ${SANDBOX_SOURCES})

# Define installation folders
set(PROJECT_BINARIES    "${CMAKE_INSTALL_PREFIX}/bin")
install(TARGETS ${EXEC_NAME} 
        RUNTIME DESTINATION ${PROJECT_BINARIES}
)