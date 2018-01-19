cmake_minimum_required(VERSION 3.0)

include(GNUInstallDirs)


add_library(foostatic STATIC foo.cpp)
set_target_properties(foostatic PROPERTIES COMPILE_DEFINITIONS STATIC
                                           COMPILE_FLAGS -fvisibility=hidden)

add_library(fooshared SHARED foo.cpp)
set_target_properties(fooshared PROPERTIES COMPILE_DEFINITIONS SHARED)

install(FILES foo.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )

install(TARGETS foostatic fooshared DESTINATION ${CMAKE_INSTALL_LIBDIR} )
