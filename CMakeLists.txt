cmake_minimum_required(VERSION 3.0.0)
project(simple_c_algorithms VERSION 0.1.0)

set(SOURCES 
    src/sort.c
    src/utils.c
    src/misc.c)

set(HEADER_FILES 
    include/sort.h
    include/utils.h
    include/misc.h)

add_library(simple_c_algorithms ${HEADER_FILES} ${SOURCES})
target_include_directories(simple_c_algorithms PUBLIC include PRIVATE src)

add_executable(main src/main.c ${HEADER_FILES} ${SOURCES})
target_include_directories(main PUBLIC include PRIVATE src})

include(CTest)
include(tests/CMakeLists.txt)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
