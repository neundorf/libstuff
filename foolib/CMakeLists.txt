cmake_minimum_required(VERSION 3.0)

include(GNUInstallDirs)


add_library(foostatic STATIC foo.cpp)

add_library(fooshared SHARED foo.cpp)

install(FILES foo.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )

install(TARGETS foostatic fooshared DESTINATION ${CMAKE_INSTALL_LIBDIR} )
