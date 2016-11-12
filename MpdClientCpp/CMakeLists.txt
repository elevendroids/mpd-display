cmake_minimum_required(VERSION 3.0)

include_directories(include)

add_library(MpdClientCpp STATIC
  source/MpdClient.cpp
  source/MpdSong.cpp
  source/MpdStatus.cpp
)

find_library(LIBMPDCLIENT mpdclient)

target_include_directories(MpdClientCpp PUBLIC include)
target_link_libraries(MpdClientCpp ${LIBMPDCLIENT})

