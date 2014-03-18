# Project setting.
project(homesoft CXX C)

# CMake version requires.
cmake_minimum_required(VERSION 2.6.2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Find Qt root directory.
set(QT_ROOT $ENV{QT_ROOT})
if(NOT QT_ROOT)
	set(QT_ROOT "${CMAKE_SOURCE_DIR}/module/qt")
endif()
message(STATUS "QT_ROOT:" ${QT_ROOT})

# Binary file directory.	
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(${PROJECT_SOURCE_DIR}/Gui)

# Build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_PACKAGE_VERSION_MAJOR "1")
set (CPACK_PACKAGE_VERSION_MINOR "0")
set (CPACK_PACKAGE_VERSION_PATCH "0")
include (CPack)
