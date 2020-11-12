add_library(ShishGL-SfmlPlatform)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Platform/SfmlPlatform)

target_include_directories(ShishGL-SfmlPlatform
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-SfmlPlatform
  PUBLIC
    ${INCROOT}/Platform.hpp
  PRIVATE
    Platform.cpp
    Draw.cpp
    Events.cpp
  )

target_compile_features(ShishGL-SfmlPlatform
  PUBLIC
    cxx_std_17
  )

find_package(SFML REQUIRED system window graphics)

target_link_libraries(ShishGL-SfmlPlatform
  PUBLIC
    ShishGL-PlatformInterface
    sfml-system
    sfml-window
    sfml-graphics
  )
