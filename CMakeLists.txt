cmake_minimum_required(VERSION 3.10)

# Setup name of project
project(Datanavy)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the sqlite library
add_subdirectory("libraries/sqlite")

# Add executable from test.cpp
add_executable(cnavy test.cpp)

target_link_libraries(cnavy PUBLIC sqlite3)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(cnavy PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/sqlite"
                          )