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

### add external projects(dependencies)
add_subdirectory("${EXTERN_PATH}/SQLiteCpp")
add_subdirectory("${EXTERN_PATH}/myhtml")
add_subdirectory("${EXTERN_PATH}/cpr")

target_include_directories(myhtml PUBLIC "${EXTERN_PATH}/myhtml/source/myhtml")
target_include_directories(myhtml PUBLIC "${EXTERN_PATH}/myhtml/source")


add_subdirectory("${SRC_PATH}/tools")
add_subdirectory("${SRC_PATH}/crawler")
add_subdirectory("${SRC_PATH}/rsm")
add_subdirectory("${SRC_PATH}/xtess")



### link libraries to executable
target_link_libraries(cnavy PUBLIC SQLiteCpp)
target_link_libraries(cnavy PUBLIC crawlerlib)
target_link_libraries(cnavy PUBLIC rsmlib)
target_link_libraries(cnavy PUBLIC xtesslib)
target_link_libraries(cnavy PUBLIC toolslib)

### include tests
add_subdirectory("${TESTS_PATH}")

### link libraries to tests_proto executable target
### build this target when neccessary with --target
target_link_libraries(tests_proto PUBLIC
        cpr::cpr
        myhtml
        SQLiteCpp
        crawlerlib
        rsmlib
        xtesslib
        toolslib
)


### helped by: https://stackoverflow.com/questions/63985373
### find and setup pthread flag(thread.h)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)

### link threads library if exists
if(TARGET Threads::Threads)
  target_link_libraries(cnavy PRIVATE Threads::Threads)
  target_link_libraries(tests_proto PRIVATE Threads::Threads)
endif()



### link any libs that depend on each other
### xtesschars requires tools and rsm require sqlite3
### linking directly to xtesslib wont work
add_dependencies(rsmlib  SQLiteCpp)
target_link_libraries(xtesscharslib toolslib)
target_link_libraries(xtesstokeniserlib PUBLIC toolslib)

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
