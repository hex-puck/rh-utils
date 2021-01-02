add_executable(meta-test main.cpp
        type_sequence_test.cpp type_sequence_test.h
        type_at_test.cpp type_at_test.h
        in_range_test.cpp in_range_test.h
        )
target_link_libraries(meta-test meta)
