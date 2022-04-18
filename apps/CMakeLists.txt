cmake_minimum_required(VERSION 3.1...3.23)

### This file is included in CMakeLists.txt
### PROJECT_SOURCE_DIR will be dir of that file
### Careful when using CMAKE_CURRENT_SOURCE_DIR

### This file creates executable target
### But performs no linking or adding of sub_directories
### Unless library is build-in e.g pthreads


### set G++ compiler -pthread flag
### this is platform specific flag
### not working if placed after adding executable
###set(CMAKE_CXX_FLAGS "-ldl -pthread")
###SET(CMAKE_EXE_LINKER_FLAGS "-ldl")


### add exectable
### add_exutable not adding executable if added as sub_directory
### including solves but needs absolute path from project_source_dir
add_executable(cnavy "${PROJECT_SOURCE_DIR}/apps/cnavy.cpp")


### add compile flags
### enable pthreads
###target_compile_options(cnavy PUBLIC ${GCC_COMPILE_FLAGS})
##set_target_properties(cnavy PROPERTIES LINKER_LANGUAGE CXX)


### include directories for program
### this does not include headers for dependencies
### only header file
target_include_directories(cnavy PUBLIC "${PROJECT_SOURCE_DIR}/include/cnavy")