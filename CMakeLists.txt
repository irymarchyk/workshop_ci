cmake_minimum_required(VERSION 3.0.0)

project(workshop_ci CXX)

set(LIB_SRC
    src/hello.cpp
)

add_library(hello STATIC ${LIB_SRC})
set_property(TARGET hello PROPERTY CXX_STANDARD 14)


set(SRCS
    src/main.cpp
)

include_directories(include)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} ${SRCS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
target_link_libraries(${PROJECT_NAME} hello)

set(TEST_SRCS
    tests/test_hello.cpp
)

add_executable(test_hello ${TEST_SRCS})

target_link_libraries(test_hello
    hello
    ${CONAN_LIBS}
)

