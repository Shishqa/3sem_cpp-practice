add_library(ShishGL-SystemInterface INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/System/Interface)

target_include_directories(ShishGL-SystemInterface
  INTERFACE
    ${INCROOT})

target_sources(ShishGL-SystemInterface
  INTERFACE
    ${INCROOT}/iSystem.hpp
  )

target_link_libraries(ShishGL-SystemInterface
  INTERFACE
    ShishGL-SystemEvents
    ShishGL-Primitives
  )

target_compile_features(ShishGL-SystemInterface
  INTERFACE
    cxx_std_17
  )

add_subdirectory(Events)
add_subdirectory(Input)
