include(CMakePackageConfigHelpers)

configure_package_config_file(
        ${CMAKE_CURRENT_LIST_DIR}/rh-utils-config.cmake.in
        ${RH_BUILD_CMAKE_DIR}/rh-utils-config.cmake
        INSTALL_DESTINATION ${RH_INSTALL_CMAKE_DIR}
)

write_basic_package_version_file(
        ${RH_BUILD_CMAKE_DIR}/rh-utils-config-version.cmake
        COMPATIBILITY SameMajorVersion
)

install(FILES
        ${RH_BUILD_CMAKE_DIR}/rh-utils-config.cmake
        ${RH_BUILD_CMAKE_DIR}/rh-utils-config-version.cmake
        DESTINATION ${RH_INSTALL_CMAKE_DIR}
        )
