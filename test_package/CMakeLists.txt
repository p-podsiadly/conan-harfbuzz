cmake_minimum_required(VERSION 2.8.12)
project(test_package)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

if(CONAN_ICU_ROOT)
    add_definitions(-DTEST_ICU)
endif()

if(WIN32)
    add_definitions(-DTEST_GDI)
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/example.ttf
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${CMAKE_PROJECT_NAME} example.c)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CONAN_LIBS})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY C_STANDARD 99)

add_executable("${CMAKE_PROJECT_NAME}_icu" test_icu.c)
target_link_libraries("${CMAKE_PROJECT_NAME}_icu" ${CONAN_LIBS})

add_executable("${CMAKE_PROJECT_NAME}_gdi" test_gdi.c)
target_link_libraries("${CMAKE_PROJECT_NAME}_gdi" ${CONAN_LIBS})
