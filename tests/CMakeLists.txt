cmake_minimum_required(VERSION 3.1)

include(ExternalProject)
find_package(Git REQUIRED)

### repo downloaded at build time
### configure time use DownloadProject
ExternalProject_Add(
    doctest
    PREFIX ${CMAKE_BINARY_DIR}/doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(doctest source_dir)
set(DOCTEST_INCLUDE_DIR ${source_dir}/doctest CACHE INTERNAL "Path to include folder for doctest")

### library links to other libs with test files
### it will be linked to executable target
add_library(testslib helpers/enable_doctest.cpp)
### dependecies of dependers of testlib find enable_doctest.hpp
target_include_directories(testslib PUBLIC helpers)

### include doctest include director and source directory
### doctest is used by testlib and test files
include_directories(${SOURCE_DIR} ${DOCTEST_INCLUDE_DIR})

### add directories with with test
### each sub directory has static lib
### the libs will be linked to executable or another lib
### currently, they are linked to testslib which link to tests executable
add_subdirectory(rsm)
add_subdirectory(crawler)
add_subdirectory(xtess)
add_subdirectory(tools)



### wait until doctest is built and downloaded before building test libraries
### files for tests depend on doctest
### using crawltestlib seems ok as testlib is already built
### dont remove this statement unless you want to use DownloadProject or git submodules
add_dependencies(crawltestlib doctest)



### include doctest for test libs
target_include_directories(testslib PUBLIC ${SOURCE_DIR} ${DOCTEST_INCLUDE_DIR})


### link test files(libraries) to testslib
target_link_libraries(testslib PUBLIC 
    crawltestlib
    rsmtestlib
    xtesstestlib
    toolstestlib
)


### link testslib with executable target
### executable target should have doctest main implementation
### main should call Enable_Doctest() from test_folder/enable_doctest.hpp
### Enable_Doctest() registers tests in testslib test files
### you can link to another executable target if you need
add_executable(tests tests.cpp)
target_link_libraries(tests testslib)

### test all features integrated
### its not formal test, just for observing.
### not linked to testslib as it does not depend test files
### Will be linked source files at root CMakeList.txt
add_executable(tests_proto tests_proto.cpp)


### checkout this:
### just trick to run doctest tests
## https://github.com/pthom/DocTest_LibTest/commit/e6373522cecdb170388e7d4c5c93b16e645089cc

### doctest does not activate tests for linked lib
### calling function libs in main solves problem
### Viktor Kirilov added doctest_force_link_static_lib_in_target()
### this seems to be issues with cmake/doctest
### last solution failed due to errors in .cmake script
