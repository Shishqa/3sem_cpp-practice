
add_library(ShishGL-Log)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Log)

target_include_directories(ShishGL-Log
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Log
  PUBLIC
    ${INCROOT}/Log.hpp
  PRIVATE
    Log.cpp
  )

target_link_libraries(ShishGL-Log
  PUBLIC
    ShishGL-Primitives
  )