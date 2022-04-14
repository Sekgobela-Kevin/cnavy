cmake_minimum_required(VERSION 3.1)

add_library(xtesstokenisertestlib  
    helpers/enable_xtess_tokeniser_test.cpp
    
    raw_tokeniser/raw_tokenise_test.cpp
    basic_tokeniser/basic_tokeniser_test.cpp
)

target_include_directories(xtesstokenisertestlib PUBLIC helpers)
