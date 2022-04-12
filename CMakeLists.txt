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

### include tests
add_subdirectory("${TESTS_PATH}")


### link any libs that depend on each other
### xtesschars requires tools and rsm require sqlite3
### linking directly to xtesslib wont work
add_dependencies(rsmlib  sqlite3)
target_link_libraries(xtesscharslib toolslib)

### link testlib to executable target
### differerent executable for tests can be created
### or maybe different executable for different tests eg crawltestlib
#target_link_libraries(cnavy PUBLIC testslib)
target_link_libraries(crawltestlib crawlerlib)
target_link_libraries(rsmtestlib rsmlib)
### this works by luck.
### addition of sublibs to toolstestlib would cause include errors.
### include dirs from toolslib and xtesslib wont reach sublibs in toolstestlib.
target_link_libraries(toolstestlib toolslib xtesslib)




### this includes dependencies from xtesslib to xtesstestlib.
### but xtesstestlib dependencies fail to get included dirs from xtesslib.
### seems like include dirs are only included in immediate files than linked
### dependecies need to be linked manually to xtesslib or its sub lib.
### this is expected as allows to restrictive access to header
### it prevent linked libs from accessing each others included dirs.
### CMake or Make team is clever
#target_link_libraries(xtesstestlib xtesslib)
target_link_libraries(xtesschrstestlib  xtesschrslib)
### requires xtess libs(charcters, tokens, etc)
target_link_libraries(xtesstokenisertestlib PUBLIC xtesscmptlib)