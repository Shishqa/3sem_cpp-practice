add_library(ShishGL-Shapes)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Graphics/Shapes)

target_include_directories(ShishGL-Shapes
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Shapes
  PUBLIC
    ${INCROOT}/Rectangle.hpp
    ${INCROOT}/Shape2D.hpp
  PRIVATE
  Rectangle.cpp
  Shape2D.cpp
  )

target_link_libraries(ShishGL-Shapes
  PUBLIC
    ShishGL-Graphics
    ShishGL-Primitives
  )
