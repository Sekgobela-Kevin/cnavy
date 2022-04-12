cmake_minimum_required(VERSION 3.1)

add_library(toolstestlib  
    helpers/enable_tools_test.cpp
    
    shared_objects/shared_objects_test.cpp
    #shared_objects/shared_characters_test.cpp
)

target_include_directories(toolstestlib PUBLIC helpers)
