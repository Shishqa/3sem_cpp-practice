add_library(ShishGL-UIFrame)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI/UIFrame)

target_include_directories(ShishGL-UIFrame
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-UIFrame
  PUBLIC
    ${INCROOT}/UIFrame.hpp
    ${INCROOT}/UIScrollbar.hpp
  PRIVATE
  ../UIScrollbar.cpp
  )

target_link_libraries(ShishGL-UIFrame
  PUBLIC
    ShishGL-UIWindow
    ShishGL-UIButton
  )