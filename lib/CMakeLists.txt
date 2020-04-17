cmake_minimum_required(VERSION 3.1)
project( p3d_library )

option (BUILD_SHARED_LIBS "Build p3d as a shared library" ON)

#==============================================================================

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# ----- Sources ----------------------------------------------

set(SOURCES
    ./serialization.cpp
    ./serialization.h
    ./project_settings.cpp
    ./project_settings.h
)

set (p3d_lib p3d)
add_library (${p3d_lib} ${SOURCES})

target_compile_features(${p3d_lib} PUBLIC cxx_std_17)

target_include_directories(${p3d_lib} PRIVATE ./../3rdparty/)
target_include_directories(${p3d_lib} PRIVATE ./src/)

target_compile_definitions (${p3d_lib} PRIVATE P3D_API_EXPORT ENTT_API_EXPORT)