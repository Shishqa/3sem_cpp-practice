add_library(ShishGL-GUI INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI)

target_include_directories(ShishGL-GUI
  INTERFACE
    ${INCROOT}
  )

target_link_libraries(ShishGL-GUI
  INTERFACE
    ShishGL-UIWindow
  )

add_subdirectory(UIWindow)

