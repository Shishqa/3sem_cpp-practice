add_library(ShishGL-Abstracts)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI/Abstracts)

target_include_directories(ShishGL-Abstracts
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Abstracts
  PUBLIC
    ${INCROOT}/ClickableWindow.hpp
    ${INCROOT}/HoldableWindow.hpp
    ${INCROOT}/DraggableWindow.hpp
  PRIVATE
    ClickableWindow.cpp
    HoldableWindow.cpp
    DraggableWindow.cpp
  )

target_link_libraries(ShishGL-Abstracts
  PUBLIC
    ShishGL-Window
  )