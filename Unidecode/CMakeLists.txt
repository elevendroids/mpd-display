cmake_minimum_required(VERSION 3.0)

include_directories(include)

add_library(Unidecode STATIC
  source/Unidecode.cpp
)

find_library(LIBICUUC icuuc)
find_library(LIBICUI18N icui18n)

target_include_directories(Unidecode PUBLIC include)
target_link_libraries(Unidecode ${LIBICUUC} ${LIBICUI18N})

