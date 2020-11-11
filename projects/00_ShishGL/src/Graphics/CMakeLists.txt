
add_library(ShishGL-Graphics INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Graphics)

target_include_directories(ShishGL-Graphics
  INTERFACE
    ${INCROOT}
  )

target_link_libraries(ShishGL-Graphics
  INTERFACE
    ShishGL-Core
    ShishGL-Shapes
  )

add_subdirectory(Shapes)
