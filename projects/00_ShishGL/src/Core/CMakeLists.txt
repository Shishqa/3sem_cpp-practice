add_library(ShishGL-Core)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core)
target_include_directories(ShishGL-Core
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Core
  PRIVATE
    CoreApplication.cpp
  PUBLIC
    ${INCROOT}/CoreApplication.hpp
  )

target_link_libraries(ShishGL-Core
  PUBLIC
    ShishGL-Log
    ShishGL-Primitives
    ShishGL-Object
    ShishGL-Event
    ShishGL-System
  )

add_subdirectory(Log)
add_subdirectory(Primitives)
add_subdirectory(Event)
add_subdirectory(Object)
add_subdirectory(System)

