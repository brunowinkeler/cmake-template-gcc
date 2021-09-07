#########################################################

# Set of Local Variables for parson location
set(LOGGER_NAME               logger)
set(LOGGER_DIR                ${PROJECT_SOURCES}/${LOGGER_NAME})

# Include the directories that are the reference
include_directories(${LOGGER_DIR}/include)

#########################################################

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

message("GERAL_SOURCES: ${GERAL_SOURCES}")

#########################################################

set(GERAL_NAME                ${LIBRARY_NAME})
set(GERAL_TYPE                ${LIBRARY_TYPE})

# Creates shared libraries with the listed sources collected in the variables
message(STATUS "Setting lib${GERAL_NAME} library as ${GERAL_TYPE}")
add_library(${GERAL_NAME} ${GERAL_TYPE} ${GERAL_SOURCES} ${GERAL_HEADERS})

# Define installation folders
install(TARGETS ${GERAL_NAME} 
        RUNTIME DESTINATION ${PROJECT_BINARIES}
        LIBRARY DESTINATION ${PROJECT_LIBS}
        ARCHIVE DESTINATION ${PROJECT_LIBS})

install(DIRECTORY ${LOGGER_DIR}/include/ 
        DESTINATION ${PROJECT_INCLUDES})
