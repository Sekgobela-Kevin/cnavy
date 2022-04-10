cmake_minimum_required(VERSION 3.1...3.23)

### represents character in oops way
### this objects will be used by tokens
### helps simplify working with text

### create library
### library not yet complete
### header for the source file be in main include folder
add_library(xtessrawtokenlib 
            raw_token.cpp
            reference_token.cpp
)

### include path with header files
target_include_directories(xtessrawtokenlib
    PUBLIC "${PROJECT_SOURCE_DIR}/include/cnavy/xtess/characters/raw_token"
)