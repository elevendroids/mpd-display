cmake_minimum_required(VERSION 3.5)

project(mpd-lcd)

add_compile_options(-std=c++11)

add_subdirectory( MpdClientCpp )

find_library(LIBMPDCLIENT mpdclient)

add_executable( mpd-lcd
  source/main.cpp
)

target_link_libraries(mpd-lcd MpdClientCpp ${LIBMPDCLIENT})

