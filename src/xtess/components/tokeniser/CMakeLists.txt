cmake_minimum_required(VERSION 3.1...3.23)

### contain componnets for tokenising text
### it may contain multiple source files or sub_dir
### each performing tokensation in their own way

### create library
### library not yet complete
### header for the source file be in main include folder
add_library(xtesstokeniserlib 
            tokeniser.cpp
            basic_tokeniser/basic_tokeniser.cpp
            raw_tokeniser/raw_tokenise.cpp
)

### include path with header files
### no target since raw_tokenise is just headers(no source)
target_include_directories(xtesstokeniserlib PUBLIC
    basic_tokeniser/include
    raw_tokeniser
)