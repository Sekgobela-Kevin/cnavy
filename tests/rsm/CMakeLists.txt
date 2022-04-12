cmake_minimum_required(VERSION 3.1)

add_library(rsmtestlib  
    helpers/enable_rsm_test.cpp
    resource_test.cpp 
    resources_test.cpp
)

target_include_directories(rsmtestlib PUBLIC helpers)
