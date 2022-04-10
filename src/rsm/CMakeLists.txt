cmake_minimum_required(VERSION 3.1...3.23)

### more features needed than just resources classes
### database features needed
### resources storage needed
### resources segmenting(dividing) needed
### other complex features
### rsm represent Resources Management
### helps manage resources
### resources is data from can be files, webpages, etc

### create library
### library not yet complete
### header for the source file be in main include folder
add_library(rsmlib resource.cpp resources.cpp)

### include path with header files
target_include_directories(rsmlib PUBLIC "${PROJECT_SOURCE_DIR}/include/cnavy/rsm")