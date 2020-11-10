add_library(ShishGL-System)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/System)

target_include_directories(ShishGL-System
  INTERFACE
    ${INCROOT})

target_sources(ShishGL-System
  PUBLIC
    ${INCROOT}/iSystem.hpp
    ${INCROOT}/System.hpp
    ${INCROOT}/Events/MouseEvent.hpp
    ${INCROOT}/Events/KeyboardEvent.hpp
    ${INCROOT}/Input/Mouse.hpp
    ${INCROOT}/Input/Keyboard.hpp
  PRIVATE
    System.cpp
    Input/Keyboard.cpp
    Events/MouseEvent.cpp
    Events/KeyboardEvent.cpp
  )

target_link_libraries(ShishGL-System
  PUBLIC
    ShishGL-Event
    ShishGL-Primitives
  )

target_compile_features(ShishGL-System
  PUBLIC
    cxx_std_17
  )

add_subdirectory(Events)
add_subdirectory(Input)