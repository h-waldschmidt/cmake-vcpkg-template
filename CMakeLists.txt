cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)

project(test-project LANGUAGES C CXX)

find_package(fmt CONFIG REQUIRED)

# an alternative would be to use -Weverything
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra")

# sometimes it can't hurt to use "-Wall -Wextra" for release
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)