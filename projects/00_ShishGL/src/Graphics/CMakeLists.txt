
add_library(ShishGL-Graphics INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Graphics)

target_include_directories(ShishGL-Graphics
  INTERFACE
    ${INCROOT}
  )

target_sources(ShishGL-Graphics
  INTERFACE
    ${INCROOT}/ColorCollection.hpp
    ${INCROOT}/WindowTypes.hpp
  )

target_link_libraries(ShishGL-Graphics
  INTERFACE
    ShishGL-Core
    ShishGL-Shapes
    ShishGL-Window
  )

add_subdirectory(Shapes)
add_subdirectory(Window)