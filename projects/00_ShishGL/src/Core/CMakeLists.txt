add_library(ShishGL-Core)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core)
target_include_directories(ShishGL-Core
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Core
  PUBLIC
    ${INCROOT}/CoreApplication.hpp
    ${INCROOT}/GraphicObject.hpp
  PRIVATE
    CoreApplication.cpp
    GraphicObject.cpp
  )

target_link_libraries(ShishGL-Core
  PUBLIC
    ShishGL-Log
    ShishGL-EventSystem
    ShishGL-System
  )

add_subdirectory(EventSystem)
add_subdirectory(Log)
add_subdirectory(System)

