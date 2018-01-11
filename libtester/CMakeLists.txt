cmake_minimum_required(VERSION 3.0)

find_library(FOOSTATIC_LIB NAMES foostatic)
find_library(FOOSHARED_LIB NAMES fooshared)

find_PATH(FOO_INCLUDE_DIR foo.h)

if(NOT FOOSTATIC_LIB OR NOT FOOSHARED_LIB OR NOT FOO_INCLUDE_DIR)
  message(FATAL_ERROR "foo not found !")
endif()

find_package(Qt4 REQUIRED)

include_directories(${FOO_INCLUDE_DIR})

add_executable(libtesterstatic main.cpp)
target_link_libraries(libtesterstatic ${FOOSTATIC_LIB} Qt4::QtCore )

add_executable(libtestershared main.cpp)
target_link_libraries(libtestershared ${FOOSHARED_LIB} Qt4::QtCore )


add_library(p1 SHARED plugin1.cpp)
target_link_libraries(p1 ${FOOSHARED_LIB} )

add_library(p2 SHARED plugin2.cpp)
target_link_libraries(p2 ${FOOSHARED_LIB} )
