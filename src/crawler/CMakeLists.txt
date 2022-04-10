cmake_minimum_required(VERSION 3.1...3.23)

### include directories(files,web, text)
add_subdirectory(files)
add_subdirectory(text)
add_subdirectory(web)

### create library
### library not yet complete
### header for the source file be in main include folder
add_library(crawlerlib input.cpp)

### link any dependencies to libraries
### crawlerlib is incomplete
### lacks source file to link everything together
### this is just test
target_link_libraries(crawlerlib PUBLIC crawlfilelib crawltextlib crawlweblib)