add_library(ShishGL-SystemEvents)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/System/Interface/Events)

target_include_directories(ShishGL-SystemEvents
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-SystemEvents
  PUBLIC
    ${INCROOT}/SystemObject.hpp
    ${INCROOT}/KeyboardEvent.hpp
    ${INCROOT}/MouseEvent.hpp
    ${INCROOT}/TimerEvent.hpp
  PRIVATE
    SystemObject.cpp
    KeyboardEvent.cpp
    MouseEvent.cpp
    TimerEvent.cpp
  )

target_link_libraries(ShishGL-SystemEvents
  PUBLIC
    ShishGL-EventSystem
    ShishGL-SystemInput
  )

target_compile_features(ShishGL-SystemEvents
  PUBLIC
    cxx_std_17
  )