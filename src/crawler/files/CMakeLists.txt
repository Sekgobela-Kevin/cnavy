cmake_minimum_required(VERSION 3.1...3.23)

### add library crawlerlib
### contains files for crawling input(web,file,text)
add_library(crawlfilelib file_text.cpp file.cpp)

### include path with header files
target_include_directories(crawlfilelib PUBLIC "${PROJECT_SOURCE_DIR}/include/cnavy/crawler")