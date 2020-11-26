add_library(YAGE-Tools)

set(INCROOT ${YAGE_SOURCE_DIR}/include/YAGE/ToolManager/Tools)

target_include_directories(YAGE-Tools
  PUBLIC
    ${INCROOT}
  )

target_sources(YAGE-Tools
  PUBLIC
    ${INCROOT}/Pen.hpp
    ${INCROOT}/Eraser.hpp
  PRIVATE
    Pen.cpp
  )

target_link_libraries(YAGE-Tools
  PUBLIC
    YAGE-ToolManager
  )