cmake_minimum_required(VERSION 3.1...3.23)

### represent components of xtess
### currently theres no component
### but just raw_tokeniser which is incomplete
add_library(xtesscmptlib components.cpp)

add_subdirectory(tokeniser)

target_link_libraries(xtesscmptlib PUBLIC xtesstokeniserlib)