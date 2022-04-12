cmake_minimum_required(VERSION 3.1...3.23)

### xtess is text proccessing code for cnavy search
### custom code to proccess text to be searched by angral
### angral is portion responsible for searching
### rsm for managing files, database and resources
### cnavy search is built on crawler, rsm, and angral

### componets of xtess give meaning to tokens
### they receive series of tokens and perform task
### with aim of retrieving something from them
### tokeniser and below componets help create 
### basic_token will be created from raw_token

### add sub_directories
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/characters")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/components")

add_library(xtesslib xtess.cpp)

# linking libs into xtesslib
target_link_libraries(xtesslib PUBLIC xtesschrslib xtesscmptlib)

### inter library linking
### components depends on characters
target_link_libraries(xtesscmptlib PUBLIC xtesschrslib)