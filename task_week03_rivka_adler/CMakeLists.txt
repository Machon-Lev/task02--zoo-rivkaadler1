cmake_minimum_required (VERSION 3.15)

project (task_week03_rivka_adler)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

add_executable (task_week03_rivka_adler "")
add_subdirectory (include)
add_subdirectory (src)