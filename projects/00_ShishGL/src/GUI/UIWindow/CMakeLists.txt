add_library(ShishGL-UIWindow INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI/UIWindow)

target_include_directories(ShishGL-UIWindow
  INTERFACE
    ${INCROOT}
  )

target_sources(ShishGL-UIWindow
  INTERFACE
    ${INCROOT}/UIWindow.hpp
    ${INCROOT}/UIWindow.ipp
  )

target_link_libraries(ShishGL-UIWindow
  INTERFACE
    ShishGL-Core
    ShishGL-Shapes
    ShishGL-Styles
  )

add_subdirectory(Shapes)
add_subdirectory(Styles)