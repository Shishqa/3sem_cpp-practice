cmake_minimum_required(VERSION 3.8)


project(ShishGL
  VERSION 1.0
  DESCRIPTION "A window manager"
  LANGUAGES CXX)


option(USE_OPEN_GL "Use OpenGL platform" OFF)
option(USE_SFML "Use SFML platform" ON)


if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  set(CMAKE_CXX_EXTENSIONS OFF)
  set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined")
  set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined")

  if (MSVC)
    add_compile_options(/W3 /WX)
  else()
    add_compile_options(-W -Wall -Wextra -Wpedantic -Werror -pedantic-errors)
  endif()

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()


add_subdirectory(src)
add_subdirectory(test)