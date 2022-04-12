cmake_minimum_required(VERSION 3.1...3.23)

### represent componets of xtess
### currently theres no component
### but just raw_tokeniser which is incomplete
add_library(xtesscmptlib components.cpp)


### add sub_directories
### no componet to include
### but base tokeniser is there
#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tokeniser")

### include sub_directories
target_include_directories(xtesscmptlib PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/tokeniser/raw_tokeniser"
)