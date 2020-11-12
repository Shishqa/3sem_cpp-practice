add_library(ShishGL-EventSystem)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/EventSystem)

target_include_directories(ShishGL-EventSystem
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-EventSystem
  PUBLIC
    ${INCROOT}/EventSystem.hpp
  PRIVATE
    ${INCROOT}/EventSystem.ipp
    EventSystem.cpp
  )

target_link_libraries(ShishGL-EventSystem
  PUBLIC
    ShishGL-LogSystem
    ShishGL-ObjectManager
    ShishGL-EventManager
  )

add_subdirectory(ObjectManager)
add_subdirectory(EventManager)