add_library(ShishGL-Shapes)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/RenderSystem/Shapes)

target_include_directories(ShishGL-Shapes
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Shapes
  PUBLIC
    ${INCROOT}/Shape2D.hpp
    ${INCROOT}/RectangleShape.hpp
    ${INCROOT}/CircleShape.hpp
  PRIVATE
    Shape2D.cpp
    RectangleShape.cpp
    CircleShape.cpp
  )

target_link_libraries(ShishGL-Shapes
  PUBLIC
    ShishGL-RenderSystem
    ShishGL-Primitives
  )
