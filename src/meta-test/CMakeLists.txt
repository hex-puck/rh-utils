add_executable(meta-test
        type_sequence_test.cpp
        type_at_test.cpp
        in_range_test.cpp
        function_info_test.cpp
        has_member_test.cpp
        )
target_link_libraries(meta-test meta)
target_link_libraries(meta-test GTest::gtest GTest::gtest_main)
