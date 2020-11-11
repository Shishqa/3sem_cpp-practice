add_library(ShishGL-SystemEvents)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/System/Events)

target_include_directories(ShishGL-SystemEvents
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-SystemEvents
  PUBLIC
    ${INCROOT}/KeyboardEvent.hpp
    ${INCROOT}/MouseEvent.hpp
  PRIVATE
    KeyboardEvent.cpp
    MouseEvent.cpp
  )

target_link_libraries(ShishGL-SystemEvents
  PUBLIC
    ShishGL-Event
    ShishGL-SystemInput
  )

target_compile_features(ShishGL-SystemEvents
  PUBLIC
    cxx_std_17
  )