install(DIRECTORY rh-utils TYPE INCLUDE FILES_MATCHING PATTERN *.h)

configure_file(rh-utils/config.h.in rh-utils/config.h @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/rh-utils/config.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/rh-utils)

file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
list(APPEND HEADERS ${CMAKE_CURRENT_BINARY_DIR}/rh-utils/config.h)

add_library(headers INTERFACE ${HEADERS})
target_include_directories(headers INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
target_include_directories(headers SYSTEM INTERFACE
        $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS headers EXPORT export-headers)
export(EXPORT export-headers NAMESPACE rh-utils::
        FILE ${RH_BUILD_CMAKEDIR}/rh-utils-headers.cmake)
install(EXPORT export-headers DESTINATION ${RH_INSTALL_CMAKEDIR}
        NAMESPACE rh-utils:: FILE rh-utils-headers.cmake)
