cmake_minimum_required(VERSION 3.0)

project(mpd-lcd)

add_compile_options(-O2 -std=c++11)

add_subdirectory( MpdClientCpp )
add_subdirectory( Unidecode )

add_executable( ${PROJECT_NAME}
  source/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} MpdClientCpp Unidecode)

