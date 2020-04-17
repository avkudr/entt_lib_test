cmake_minimum_required(VERSION 3.1)
project( p3d_app )

#==============================================================================

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----- Sources ----------------------------------------------

add_executable(p3d_app ./main.cpp)

target_compile_definitions(p3d_app PRIVATE P3D_API_IMPORT ENTT_API_IMPORT)
target_include_directories(p3d_app SYSTEM PRIVATE ./../3rdparty/)

# ----- add library

set(P3D_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/../lib/${CMAKE_BUILD_TYPE})
target_include_directories(p3d_app SYSTEM PRIVATE ./../lib/)

target_link_directories(p3d_app PRIVATE ${P3D_LIB_DIR} )
target_link_libraries(p3d_app PRIVATE p3d )

add_custom_command(TARGET p3d_app POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${P3D_LIB_DIR}/p3d.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:p3d_app>)                 # <--this is out-file path