add_library(ShishGL-SmflPlatform)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Platform/SfmlPlatform)
target_include_directories(ShishGL-SFML-Platform
  PUBLIC
    ${INCROOT})

target_sources(ShishGL-SfmlPlatform
  PRIVATE
    Draw.cpp
    Events.cpp
  System.cpp
  PUBLIC
    ${INCROOT})