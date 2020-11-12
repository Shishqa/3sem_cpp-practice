add_library(ShishGL-EventManager)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/EventSystem/EventManager)

target_include_directories(ShishGL-EventManager
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-EventManager
  PUBLIC
    ${INCROOT}/Event.hpp
    ${INCROOT}/EventManager.hpp
  PRIVATE
    ${INCROOT}/EventManager.ipp
    EventManager.cpp
    Event.cpp
  )

target_link_libraries(ShishGL-EventManager
  PUBLIC
    ShishGL-LogSystem
    ShishGL-ObjectManager
  )