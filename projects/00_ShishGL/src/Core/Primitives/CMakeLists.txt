add_library(ShishGL-Primitives)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Primitives)

target_include_directories(ShishGL-Primitives
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Primitives
  PUBLIC
    ${INCROOT}/Vector2.hpp
    ${INCROOT}/Segment2.hpp
    ${INCROOT}/Shape2D.hpp
    ${INCROOT}/Color.hpp
    ${INCROOT}/Time.hpp
  PRIVATE
    ${INCROOT}/Vector2.ipp
    Vector2.cpp
    Shape2D.cpp
    Time.cpp
  )

target_compile_features(ShishGL-Primitives
  PUBLIC
    cxx_std_17
  )