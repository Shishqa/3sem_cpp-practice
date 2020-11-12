add_library(ShishGL-PlatformInterface INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Platform/Interface)

target_include_directories(ShishGL-PlatformInterface
  INTERFACE
    ${INCROOT})

target_sources(ShishGL-PlatformInterface
  INTERFACE
    ${INCROOT}/IPlatform.hpp
  )

target_link_libraries(ShishGL-PlatformInterface
  INTERFACE
    ShishGL-Primitives
    ShishGL-LogSystem
    ShishGL-PlatformEvents
    ShishGL-PlatformInput
  )

target_compile_features(ShishGL-PlatformInterface
  INTERFACE
    cxx_std_17
  )

add_subdirectory(Events)
add_subdirectory(Input)