add_library(ShishGL-Event)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Event)

target_include_directories(ShishGL-Event
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Event
  PUBLIC
    ${INCROOT}/Event.hpp
    ${INCROOT}/EventSystem.hpp
    ${INCROOT}/SubscriptionManager.hpp
    ${INCROOT}/TimerEvent.hpp
  PRIVATE
    Event.cpp
    EventSystem.cpp
    ${INCROOT}/EventSystem.ipp
    SubscriptionManager.cpp
    TimerEvent.cpp
  )

target_link_libraries(ShishGL-Event
  PUBLIC
    ShishGL-Log
    ShishGL-Object
    ShishGL-Primitives)