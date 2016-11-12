cmake_minimum_required(VERSION 3.5)

include_directories(include)

add_library(MpdClientCpp
  source/MpdClient.cpp
  source/MpdSong.cpp
  source/MpdStatus.cpp
)

target_include_directories(MpdClientCpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

