cmake_minimum_required(VERSION 3.1...3.23)

### represents character in oops way
### this objects will be used by tokens
### helps simplify working with text

### create library
### library not yet complete
### header for the source file be in main include folder
add_library(xtesscharslib 
            characters.cpp
            bool_characters.cpp 
            ratio_characters.cpp 
            summary_characters.cpp 
            static_compare_characters.cpp 
            compare_characters.cpp 
)


### include path with header files
target_include_directories(xtesscharslib PUBLIC
    "${PROJECT_SOURCE_DIR}/include/cnavy/xtess/characters/characters"
)
