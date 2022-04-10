cmake_minimum_required(VERSION 3.1...3.23)

### set project details
project(datanavy VERSION 1.0 
        DESCRIPTION "Simple search engine" 
        LANGUAGES C CXX
)

### set path variables
set(INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include")
set(EXTERN_PATH "${PROJECT_SOURCE_DIR}/extern")
set(APPS_PATH "${PROJECT_SOURCE_DIR}/apps")
set(SCRIPTS_PATH "${PROJECT_SOURCE_DIR}/scripts")
set(TESTS_PATH "${PROJECT_SOURCE_DIR}/tests")
set(SRC_PATH "${PROJECT_SOURCE_DIR}/src")


#include cmake files/scripts
include("${APPS_PATH}/CMakeLists.txt")

### add sub_directores(librarie/sub_projecs)
add_subdirectory("${EXTERN_PATH}/sqlite")
add_subdirectory("${SRC_PATH}/tools")
add_subdirectory("${SRC_PATH}/crawler")
add_subdirectory("${SRC_PATH}/rsm")
add_subdirectory("${SRC_PATH}/xtess")


### link libraries to executable
target_link_libraries(cnavy PUBLIC sqlite3)
target_link_libraries(cnavy PUBLIC crawlerlib)
target_link_libraries(cnavy PUBLIC rsmlib)
target_link_libraries(cnavy PUBLIC xtesslib)
target_link_libraries(cnavy PUBLIC toolslib)

### extrenal library linking(toolslib)
### library provide tools
target_link_libraries(xtesscharslib toolslib)
