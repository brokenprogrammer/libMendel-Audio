cmake_minimum_required(VERSION 2.8.7)
project(libMendel-Audio)
include(ExternalProject)
find_package(Git REQUIRED)

# Directory for the tests
set(TEST_DIR ${PROJECT_SOURCE_DIR})

# Sources files to be tested and / or included
# TODO: Find better solution for this / clean up file.
set(TEST_SOURCES
    ${TEST_DIR}/BaseTest.cpp
    ${TEST_DIR}/FlacFileTests.cpp
    ${TEST_DIR}/IOUtilsTests.cpp
    ${TEST_DIR}/../src/libMendelAudio.h
    ${TEST_DIR}/../src/File/AudioFiles.h
    ${TEST_DIR}/../src/File/MusicFile.h
    ${TEST_DIR}/../src/File/MusicFile.cpp
    ${TEST_DIR}/../src/File/FlacFile.h
    ${TEST_DIR}/../src/File/FlacFile.cpp
    ${TEST_DIR}/../src/File/IOUtils.h
    ${TEST_DIR}/../src/File/IOUtils.cpp
)

# Making the CMake script fetch Catch from github
# and use it as an external project
ExternalProject_Add(
    catch
    PREFIX ${CMAKE_BINARY_DIR}/catch
    GIT_REPOSITORY https://github.com/philsquared/Catch.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
   )

# Expose required variable (CATCH_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(catch source_dir)
set(CATCH_INCLUDE_DIR ${source_dir}/single_include CACHE INTERNAL "include")

# Includes Catch in the project:

add_library(Catch INTERFACE)
add_dependencies(Catch Catch-External)
target_include_directories(Catch INTERFACE ${CMAKE_BINARY_DIR}/external/Catch/include)

enable_testing(true)  # Enables unit-testing.

#Adds all the sources to a single test base.
add_executable(libMendel_Test ${TEST_SOURCES})
add_test(NAME TestBase COMMAND libMendel_Test)
