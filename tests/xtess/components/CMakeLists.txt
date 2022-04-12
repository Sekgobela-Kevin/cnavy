cmake_minimum_required(VERSION 3.1)

add_library(xtesscmpttestlib  
    helpers/enable_xtess_components_test.cpp
)

add_subdirectory(tokeniser)
target_link_libraries(xtesscmpttestlib PUBLIC xtesstokenisertestlib)

target_include_directories(xtesscmpttestlib PUBLIC helpers)
