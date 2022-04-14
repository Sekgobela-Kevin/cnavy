### add sqlite3 as library
### set language of sqlite as C
add_library(sqlite3 sqlite3.c)
set_target_properties(sqlite3 PROPERTIES LINKER_LANGUAGE C)

### include directory with sqlite headers
### directory shared with other dependencies(INTERFACE)
target_include_directories(sqlite3 INTERFACE "${SOURCE_DIR}")


### helped by: https://gist.github.com/kwk/3595733
target_link_libraries(sqlite3 ${CMAKE_DL_LIBS})
