configure_file(config.h.in ${RH_BUILD_INCLUDEDIR}/config.h)

add_subdirectory(meta)

if ($CACHE{RH_UTILS_ENABLE_TEST})
    message(VERBOSE "test is enabled")
    find_package(GTest REQUIRED gtest gtest_main)
    add_subdirectory(meta-test)
else ()
    message(VERBOSE "test is disabled")
endif ()
