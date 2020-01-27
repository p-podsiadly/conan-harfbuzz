cmake_minimum_required(VERSION 2.8.12)
project(cmake_wrapper)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

include("${CMAKE_CURRENT_BINARY_DIR}/../conanbuildinfo.cmake")
conan_basic_setup()

set(THIRD_PARTY_LIBS ${CONAN_LIBS})

add_subdirectory(source_subfolder)
