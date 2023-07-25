cmake_minimum_required(VERSION 3.10)
project(progp1)

# Compilation settings for C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DROOT_PROJ_DIR='\"${PROJECT_SOURCE_DIR}/data\"'")

# External libraries
include_directories(external/stb)
add_subdirectory(external/gtest)
include_directories(external/gtest/googletest/include)

# RGB library
include_directories(.)
add_library(rgb
        rgb/color.cpp
        rgb/image.cpp
        rgb/script.cpp
        png/png.cpp)

if(TEACHER_VERSION)
    add_library(rgbs
        rgb/color-s.cpp
        rgb/image-s.cpp
        rgb/script-s.cpp
        png/png.cpp)
endif(TEACHER_VERSION)

# Test programs
add_executable(color_test test/color_test.cpp)
target_link_libraries(color_test rgb gtest gtest_main pthread)
add_executable(image_test test/image_test.cpp)
target_link_libraries(image_test rgb gtest gtest_main pthread)
add_executable(script_test test/script_test.cpp)
target_link_libraries(script_test rgb gtest gtest_main pthread)

if(TEACHER_VERSION)
    add_executable(color_test_s test/color_test.cpp)
    target_link_libraries(color_test_s rgbs gtest gtest_main pthread)
    add_executable(image_test_s test/image_test.cpp)
    target_link_libraries(image_test_s rgbs gtest gtest_main pthread)
    add_executable(script_test_s test/script_test.cpp)
    target_link_libraries(script_test_s rgbs gtest gtest_main pthread)
endif(TEACHER_VERSION)

# Utility programs
add_executable(run_script programs/run_script.cpp)
target_link_libraries(run_script rgb)
add_executable(image_diff programs/image_diff.cpp)
target_link_libraries(image_diff rgb)
add_executable(image_dump programs/image_dump.cpp)
target_link_libraries(image_dump rgb)

if(TEACHER_VERSION)
    add_executable(run_script_s programs/run_script.cpp)
    target_link_libraries(run_script_s rgbs)
    add_executable(image_diff_s programs/image_diff.cpp)
    target_link_libraries(image_diff_s rgbs)
    add_executable(image_dump_s programs/image_dump.cpp)
    target_link_libraries(image_dump_s rgbs)
endif(TEACHER_VERSION)

# Doxygen-generated documentation (doxygen needs to be installed)
find_package(Doxygen)

if(DOXYGEN_FOUND)
    set(DOXYGEN_EXTRACT_PRIVATE "YES")
    set(DOXYGEN_EXTRACT_STATIC "YES")
    set(DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
    doxygen_add_docs(docs
            ${PROJECT_SOURCE_DIR}/rgb)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)

# Packaging

set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_PACKAGE_NAME "delivery")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "delivery")
install(DIRECTORY "rgb" DESTINATION "rgb")
file(READ ${PROJECT_SOURCE_DIR}/.cpack_ignore _cpack_ignore)
string(REGEX REPLACE "\n" ";" _cpack_ignore ${_cpack_ignore})
set(CPACK_SOURCE_IGNORE_FILES "${_cpack_ignore}")
include(CPack)