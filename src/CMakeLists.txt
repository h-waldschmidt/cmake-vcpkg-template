find_package(fmt CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sublibrary)

add_subdirectory(sublibrary)

# if test is enabled, add test target
if(BUILD_TESTING)
    add_executable(${PROJECT_NAME}_test main_test.cpp)

    target_link_libraries(${PROJECT_NAME}_test PRIVATE sublibrary_test)
    target_link_libraries(${PROJECT_NAME}_test PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

    gtest_discover_tests(${PROJECT_NAME}_test)
endif()
