
add_library(ShishGL-Window)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Graphics/Window)

target_include_directories(ShishGL-Window
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Window
  PUBLIC
    ${INCROOT}/Viewport.hpp
    ${INCROOT}/Window.hpp
    ${INCROOT}/WindowManager.hpp
  PRIVATE
    ${INCROOT}/Window.ipp
    ${INCROOT}/WindowManager.ipp
    Window.cpp
    #${INCROOT}/ClickableWindow.hpp
    #${INCROOT}/ClickableWindow.ipp
    #${INCROOT}/HoldableWindow.hpp
    #${INCROOT}/HoldableWindow.ipp
    #${INCROOT}/DraggableWindow.hpp
    #${INCROOT}/DraggableWindow.ipp
    #${INCROOT}/SlidableWindow.hpp
    #${INCROOT}/SlidableWindow.ipp
  )

target_link_libraries(ShishGL-Window
  PUBLIC
    ShishGL-Core
    ShishGL-Shapes
  )