add_subdirectory(meta)

if (RH_UTILS_ENABLE_TEST)
    add_subdirectory(meta-test)
endif ()

# config.h
set(RH_RESULT_CONFIG_HEADER ${PROJECT_SOURCE_DIR}/include/rh-utils/config.h)
configure_file(config.h.in ${RH_RESULT_CONFIG_HEADER} @ONLY)
