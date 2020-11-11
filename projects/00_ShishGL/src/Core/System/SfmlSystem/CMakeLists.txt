
add_library(ShishGL-SfmlSystem)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/System/SfmlSystem)

target_include_directories(ShishGL-SfmlSystem
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-SfmlSystem
  PUBLIC
    ${INCROOT}/System.hpp
  PRIVATE
    System.cpp
    Draw.cpp
    Events.cpp
  )

target_compile_features(ShishGL-SfmlSystem
  PUBLIC
    cxx_std_17
  )

find_package(SFML REQUIRED system window graphics)

target_link_libraries(ShishGL-SfmlSystem
  PUBLIC
    ShishGL-SystemInterface
    sfml-system
    sfml-window
    sfml-graphics
  )
