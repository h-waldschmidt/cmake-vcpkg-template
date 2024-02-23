cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# on MacOS and Linux the default is static binding, but to prevent problems with LGPL, we use dynamic binding
if(APPLE)
    set(VCPKG_TARGET_TRIPLET arm64-osx-dynamic)
elseif(UNIX AND VCPKG_TARGET_ARCHITECTURE==x64)
    set(VCPKG_TARGET_TRIPLET x64-linux-dynamic)
elseif(UNIX AND VCPKG_TARGET_ARCHITECTURE==arm64)
    set(VCPKG_TARGET_TRIPLET arm64-linux-dynamic)
endif()

project(test-project LANGUAGES C CXX)

include(CheckIPOSupported)

check_ipo_supported(RESULT supported OUTPUT error)

if(supported AND CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "IPO / LTO enabled")
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
    message(STATUS "IPO / LTO not enabled: <${error}>")
endif()

# an alternative would be to use -Weverything
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra")

# sometimes it can't hurt to use "-Wall -Wextra" for release
# NOTE: This is reduntant, as the default is already "-O3"
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if(BUILD_TESTING)
    enable_testing()
    include(GoogleTest)
    find_package(GTest CONFIG REQUIRED)
endif()

add_subdirectory(src)
