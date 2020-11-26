add_library(ShishGL-UIScrollbar)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI/UIScrollbar)

target_include_directories(ShishGL-UIScrollbar
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-UIScrollbar
  PUBLIC
    ${INCROOT}/UIScrollbar.hpp
    ${INCROOT}/UIScrollbarButton.hpp
    ${INCROOT}/UIScrollbarSlider.hpp
  PRIVATE
  ../UIScrollbar.cpp
    UIScrollbarButton.cpp
    UIScrollbarSlider.cpp
  )

target_link_libraries(ShishGL-UIScrollbar
  PUBLIC
    ShishGL-UIButton
  )