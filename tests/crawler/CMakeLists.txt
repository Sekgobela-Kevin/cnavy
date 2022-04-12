cmake_minimum_required(VERSION 3.1)

add_library(crawltestlib  
    helpers/enable_crawler_test.cpp
    file_test.cpp 
    input_webpage_test.cpp
    input_text_test.cpp
)

target_include_directories(crawltestlib PUBLIC helpers)
