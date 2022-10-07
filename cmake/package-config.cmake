include(CMakePackageConfigHelpers)

set(CONFIG_FILE_IN ${CMAKE_CURRENT_LIST_DIR}/rh-utils-config.cmake.in)
set(CONFIG_FILE ${RH_BUILD_CMAKEDIR}/rh-utils-config.cmake)
set(CONFIG_VERSION_FILE ${RH_BUILD_CMAKEDIR}/rh-utils-config-version.cmake)

configure_package_config_file(${CONFIG_FILE_IN} ${CONFIG_FILE}
        INSTALL_DESTINATION ${RH_INSTALL_CMAKEDIR})

write_basic_package_version_file(${CONFIG_VERSION_FILE}
        COMPATIBILITY SameMajorVersion)

install(FILES ${CONFIG_FILE} ${CONFIG_VERSION_FILE}
        DESTINATION ${RH_INSTALL_CMAKEDIR})

unset(CONFIG_FILE_IN)
unset(CONFIG_FILE)
unset(CONFIG_VERSION_FILE)
