# Include headers to be accessible by sources
include_directories(${PROJECT_INCLUDES})

# Collect sources and headers into the variables
file(GLOB_RECURSE GERAL_HEADERS 
        "*.h"
        "*.hpp"
        "*.hxx"
        )

file(GLOB_RECURSE GERAL_SOURCES
        "*.c"
        "*.cpp"
        "*.cxx"
        )

#########################################################

set(GERAL_NAME                ${LIBRARY_NAME})
set(GERAL_TYPE                ${LIBRARY_TYPE})

# Creates shared libraries with the listed sources collected in the variables
message(STATUS "Setting lib${GERAL_NAME} library as ${GERAL_TYPE}")
add_library(${GERAL_NAME} ${GERAL_TYPE} ${GERAL_SOURCES} ${GERAL_HEADERS})

# Define installation folders
install(TARGETS ${GERAL_NAME} 
        RUNTIME DESTINATION ${INSTALL_PROJECT_BINARIES}
        LIBRARY DESTINATION ${INSTALL_PROJECT_LIBS}
        ARCHIVE DESTINATION ${INSTALL_PROJECT_LIBS})

install(DIRECTORY ${PROJECT_INCLUDES}/
        DESTINATION ${INSTALL_PROJECT_INCLUDES})
