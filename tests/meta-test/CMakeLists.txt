add_compile_test(in_range_test in_range_test.cpp)
add_compile_test(type_at_test type_at_test.cpp)
add_compile_test(type_sequence_test type_sequence_test.cpp)

add_compile_test(will_fail.type_at_test.empty WILL_FAIL
        will_fail.type_at_test.empty.cpp)
add_compile_test(will_fail.type_at_test.large_index WILL_FAIL
        will_fail.type_at_test.large_index.cpp)
