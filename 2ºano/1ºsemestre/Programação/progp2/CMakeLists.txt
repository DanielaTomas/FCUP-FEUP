cmake_minimum_required(VERSION 3.10)
project(progp2)

# Compilation settings for C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DROOT_PROJ_DIR='\"${PROJECT_SOURCE_DIR}/data\"'")

# External libraries
include_directories(external/stb)
add_subdirectory(external/gtest)
include_directories(external/gtest/googletest/include)
add_library(tinyxml2 external/tinyxml2/src/tinyxml2.cpp)
include_directories(external/tinyxml2/src)

# SVG library
include_directories(.)

if(TEACHER_VERSION)
    add_library(svg
            svg/png_image.cpp
            svg/svg_to_png-s.cpp
            svg/shape.cpp
            svg/elements-s.cpp)
else(TEACHER_VERSION)
    add_library(svg
            svg/png_image.cpp
            svg/svg_to_png.cpp
            svg/shape.cpp
            svg/elements.cpp)
endif(TEACHER_VERSION)


# Test programs
add_executable(test_ellipse test/test_ellipse.cpp)
target_link_libraries(test_ellipse svg tinyxml2 gtest gtest_main pthread)

add_executable(test_polygon test/test_polygon.cpp)
target_link_libraries(test_polygon svg tinyxml2 gtest gtest_main pthread)

add_executable(test_polyline test/test_polyline.cpp)
target_link_libraries(test_polyline svg tinyxml2 gtest gtest_main pthread)

add_executable(test_group test/test_group.cpp)
target_link_libraries(test_group svg tinyxml2 gtest gtest_main pthread)

add_executable(test_use test/test_use.cpp)
target_link_libraries(test_use svg tinyxml2 gtest gtest_main pthread)

add_executable(test_transform test/test_transform.cpp)
target_link_libraries(test_transform svg tinyxml2 gtest gtest_main pthread)

# Utility programs
add_executable(convert programs/convert.cpp)
target_link_libraries(convert svg tinyxml2)
add_executable(png_diff programs/png_diff.cpp)
target_link_libraries(png_diff svg tinyxml2)
add_executable(png_dump programs/png_dump.cpp)
target_link_libraries(png_dump svg tinyxml2)
add_executable(xmltest programs/xmltest.cpp)
target_link_libraries(xmltest tinyxml2)



