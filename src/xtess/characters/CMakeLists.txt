cmake_minimum_required(VERSION 3.1...3.23)


### include sub_directories
add_subdirectory(character)
add_subdirectory(characters)
add_subdirectory(raw_token)

add_library(xtesschrslib characters.cpp)

### link lib that depend on each other
target_link_libraries(xtesscharslib xtesscharlib)
target_link_libraries(xtessrawtokenlib xtesscharslib)

### link all libs together to one
target_link_libraries(xtesschrslib 
    xtesscharlib 
    xtesscharslib 
    xtessrawtokenlib 
)
