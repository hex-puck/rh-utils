if (NOT BUILD_TESTING)
    return()
endif ()

macro(add_compile_test _name)
    get_filename_component(real_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    set(real_name ${real_name}.${_name})
    set(sources ${ARGN})
    list(GET sources 0 will_fail)
    if (will_fail STREQUAL WILL_FAIL)
        list(REMOVE_AT sources 0)
    endif ()

    add_library(${real_name} EXCLUDE_FROM_ALL ${sources})
    target_link_libraries(${real_name} PRIVATE meta)

    add_test(NAME ${real_name}
            COMMAND ${CMAKE_COMMAND}
            --build ${PROJECT_BINARY_DIR}
            --target ${real_name})
    if (will_fail STREQUAL WILL_FAIL)
        set_tests_properties(${real_name} PROPERTIES WILL_FAIL TRUE)
    endif ()

    unset(real_name)
    unset(sources)
    unset(will_fail)
endmacro()

add_subdirectory(meta-test)
