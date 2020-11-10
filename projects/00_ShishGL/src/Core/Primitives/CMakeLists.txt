add_library(ShishGL-Primitives)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Primitives)

target_include_directories(ShishGL-Primitives
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Primitives
  PUBLIC
    ${INCROOT}/Vector2.hpp
    ${INCROOT}/Color.hpp
    ${INCROOT}/ColorCollection.hpp
    ${INCROOT}/Text.hpp
    ${INCROOT}/Time.hpp
  PRIVATE
    ${INCROOT}/Vector2.ipp
    Time.cpp
    Text.cpp
  )