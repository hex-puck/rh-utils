cmake_minimum_required(VERSION 3.19)
project(rh-utils
        VERSION 0.2.0
        DESCRIPTION "Toolkit under C++14 and above"
        HOMEPAGE_URL "https://github.com/hex-puck/rh-utils")

# project setting
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_DEBUG_POSTFIX _d)

include(CTest)
include(GenerateExportHeader)
include(GNUInstallDirs)

set(REL_CMAKEDIR ${CMAKE_INSTALL_LIBDIR}/cmake/rh-utils-${PROJECT_VERSION})
set(RH_INSTALL_CMAKEDIR ${REL_CMAKEDIR})
set(RH_BUILD_CMAKEDIR ${PROJECT_BINARY_DIR}/${REL_CMAKEDIR})
unset(REL_CMAKEDIR)

include(cmake/package-config.cmake)

if (BUILD_TESTING)
    find_package(GTest REQUIRED CONFIG)
endif ()

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)
