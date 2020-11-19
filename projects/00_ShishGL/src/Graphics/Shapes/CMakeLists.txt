add_library(ShishGL-Shapes)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Graphics/Shapes)

target_include_directories(ShishGL-Shapes
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Shapes
  PUBLIC
    ${INCROOT}/Rectangle.hpp
    ${INCROOT}/Circle.hpp
    ${INCROOT}/Shape2D.hpp
  PRIVATE
    Rectangle.cpp
    Circle.cpp
  ../../Core/Primitives/Shape2D.cpp
  )

target_link_libraries(ShishGL-Shapes
  PUBLIC
    ShishGL-Core
  )
