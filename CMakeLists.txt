cmake_minimum_required(VERSION 3.12)
project(rh-utils
        VERSION 0.1
        DESCRIPTION "C++14 下的工具集"
        HOMEPAGE_URL "https://github.com/hex-puck/rh-utils"
        LANGUAGES C CXX
        )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX d)

set(RH_UTILS_ENABLE_TEST ON CACHE BOOL "是否启用测试模块")

include(GNUInstallDirs)
set(RH_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_PROJECT_NAME})
set(RH_BUILD_INCLUDEDIR ${CMAKE_CURRENT_BINARY_DIR}/include/${CMAKE_PROJECT_NAME})

add_subdirectory(meta)

if ($CACHE{RH_UTILS_ENABLE_TEST})
    message(VERBOSE "test is enabled")
    add_subdirectory(meta-test)
else ()
    message(VERBOSE "test is disabled")
endif ()
