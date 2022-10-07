add_library(meta INTERFACE)
target_link_libraries(meta INTERFACE headers)

install(TARGETS meta EXPORT export-meta)
export(EXPORT export-meta NAMESPACE rh-utils::
        FILE ${RH_BUILD_CMAKEDIR}/rh-utils-meta.cmake)
install(EXPORT export-meta DESTINATION ${RH_INSTALL_CMAKEDIR}
        NAMESPACE rh-utils:: FILE rh-utils-meta.cmake)
