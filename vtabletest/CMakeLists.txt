cmake_minimum_required(VERSION 3.0)

find_package(Qt4 REQUIRED)

add_executable(vtabletester main.cpp)
target_link_libraries(vtabletester Qt4::QtCore )


add_library(vtplugin SHARED vtplugin.cpp pluginclasses.cpp)
#target_link_libraries(vtplugin ${FOOSHARED_LIB} )
