add_library(meta INTERFACE)
target_include_directories(meta INTERFACE
        $<BUILD_INTERFACE:${RH_BUILD_INCLUDEDIR}/..>
        $<INSTALL_INTERFACE:include>
        )

file(GLOB headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
list(REMOVE_ITEM headers meta.h)

if (headers)
    file(COPY ${headers} DESTINATION ${RH_BUILD_INCLUDEDIR}/meta)
    install(FILES ${headers} DESTINATION ${RH_INSTALL_INCLUDEDIR}/meta)
endif ()

file(COPY meta.h DESTINATION ${RH_BUILD_INCLUDEDIR})
install(FILES meta.h DESTINATION ${RH_INSTALL_INCLUDEDIR})

install(TARGETS meta EXPORT meta-config)
install(EXPORT meta-config DESTINATION lib/cmake)
