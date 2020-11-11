add_library(ShishGL-System INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/System)

target_include_directories(ShishGL-System
  INTERFACE
    ${INCROOT}
  )

target_link_libraries(ShishGL-System
  INTERFACE
    ShishGL-SystemInterface
  )

target_sources(ShishGL-System
  INTERFACE
    ${INCROOT}/System.hpp
  )

target_compile_features(ShishGL-System
  INTERFACE
    cxx_std_17
  )

add_subdirectory(Interface)

if (USE_SFML)

  add_subdirectory(SfmlSystem)
  target_link_libraries(ShishGL-System
    INTERFACE
      ShishGL-SfmlSystem
    )
  target_compile_definitions(ShishGL-System
    INTERFACE
      USE_SFML
    )

endif (USE_SFML)
