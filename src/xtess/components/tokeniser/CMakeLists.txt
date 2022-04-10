cmake_minimum_required(VERSION 3.1...3.23)

### contain componnets for tokenising text
### it may contain multiple source files or sub_dir
### each performing tokensation in their own way

### create library
### library not yet complete
### header for the source file be in main include folder
#add_library(xtesscharslib 
#            base_tokeniser/resource.cpp 
#            resources.cpp)

### include path with header files
### no target since raw_tokenise is just headers(no source)
include_directories(raw_tokeniser)