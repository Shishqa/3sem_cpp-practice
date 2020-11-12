add_library(ShishGL-Platform INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Platform)

target_include_directories(ShishGL-Platform
  INTERFACE
    ${INCROOT}
  )

target_link_libraries(ShishGL-Platform
  INTERFACE
    ShishGL-PlatformInterface
  )

target_sources(ShishGL-Platform
  INTERFACE
    ${INCROOT}/Platform.hpp
  )

target_compile_features(ShishGL-Platform
  INTERFACE
    cxx_std_17
  )

add_subdirectory(Interface)

if (USE_SFML)

  add_subdirectory(SfmlPlatform)
  target_link_libraries(ShishGL-Platform
    INTERFACE
      ShishGL-SfmlPlatform
    )
  target_compile_definitions(ShishGL-Platform
    INTERFACE
      USE_SFML
    )

endif (USE_SFML)
