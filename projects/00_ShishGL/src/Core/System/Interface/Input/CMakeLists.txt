add_library(ShishGL-SystemInput)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/System/Interface/Input)

target_include_directories(ShishGL-SystemInput
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-SystemInput
  PUBLIC
    ${INCROOT}/Mouse.hpp
    ${INCROOT}/Keyboard.hpp
  PRIVATE
  Keyboard.cpp
  )

target_compile_features(ShishGL-SystemInput
  PUBLIC
    cxx_std_17
  )