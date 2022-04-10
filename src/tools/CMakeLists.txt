cmake_minimum_required(VERSION 3.1...3.23)

### handles c++ files containing common classes and functions
### currently just include bool_set and shared_objects
### bool_set is boolset as vector(nut different)

### create library
### library not yet complete
### header for the source file be in main include folder
add_library(toolslib
            "${CMAKE_CURRENT_SOURCE_DIR}/bool_set/bool_set.cpp"
)

### include path with header files
### files not included 
### dont know why
target_include_directories(toolslib PUBLIC "${PROJECT_SOURCE_DIR}/include/cnavy/tools")