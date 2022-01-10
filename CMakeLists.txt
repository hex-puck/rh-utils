cmake_minimum_required(VERSION 3.16)
project(rh-utils
        VERSION 0.1.0
        DESCRIPTION "Toolkit under C++14 and above"
        HOMEPAGE_URL "https://github.com/hex-puck/rh-utils"
        )

# cache entries
option(RH_UTILS_ENABLE_TEST "Enable test" ON)

# project setting
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX d)

if (RH_UTILS_ENABLE_TEST)
    find_package(GTest REQUIRED CONFIG)
endif ()

include(GenerateExportHeader)
include(GNUInstallDirs)

# common variables
set(RH_ENV_TARGET env)
set(RH_EXPORT_PREFIX ${PROJECT_NAME}-)
set(RH_EXPORT_SUFFIX -targets)
set(RH_EXPORT_NAMESPACE ${PROJECT_NAME}::)
set(RH_BUILD_CMAKE_DIR ${PROJECT_BINARY_DIR}/${PROJECT_NAME})

# install paths (in relative format)
set(RH_INSTALL_BIN_DIR ${CMAKE_INSTALL_BINDIR})
set(RH_INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_INCLUDEDIR})
set(RH_INSTALL_LIB_DIR ${CMAKE_INSTALL_LIBDIR})
set(RH_INSTALL_CMAKE_DIR ${RH_INSTALL_LIB_DIR}/cmake/${PROJECT_NAME})

include(cmake/env.cmake)
include(cmake/package-config.cmake)

add_subdirectory(include)
add_subdirectory(src)
