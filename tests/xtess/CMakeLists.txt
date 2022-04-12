cmake_minimum_required(VERSION 3.1)

add_library(xtesstestlib  
    helpers/enable_xtess_test.cpp
)

add_subdirectory(components)
add_subdirectory(characters)


target_link_libraries(xtesstestlib 
    xtesscmpttestlib
    xtesschrstestlib
)

target_include_directories(xtesstestlib PUBLIC helpers)
