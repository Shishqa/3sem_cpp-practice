
add_library(ShishGL-Window INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Graphics/Window)

target_include_directories(ShishGL-Window
  INTERFACE
    ${INCROOT}
  )

target_sources(ShishGL-Window
  INTERFACE
    ${INCROOT}/Window.hpp
    ${INCROOT}/Window.ipp
    ${INCROOT}/ClickableWindow.hpp
    ${INCROOT}/ClickableWindow.ipp
    ${INCROOT}/HoldableWindow.hpp
    ${INCROOT}/HoldableWindow.ipp
    ${INCROOT}/DraggableWindow.hpp
    ${INCROOT}/DraggableWindow.ipp
    ${INCROOT}/SlidableWindow.hpp
    ${INCROOT}/SlidableWindow.ipp
  )

target_link_libraries(ShishGL-Window
  INTERFACE
    ShishGL-Shapes
  )