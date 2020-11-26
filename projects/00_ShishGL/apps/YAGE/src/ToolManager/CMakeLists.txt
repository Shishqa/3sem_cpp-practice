add_library(YAGE-ToolManager)

set(INCROOT ${YAGE_SOURCE_DIR}/include/YAGE/ToolManager)

target_include_directories(YAGE-ToolManager
  PUBLIC
    ${INCROOT}
    ${INCROOT}/Tools
  )

target_sources(YAGE-ToolManager
  PUBLIC
    ${INCROOT}/ToolManager.hpp
    ${INCROOT}/ToolSelector.hpp
    ${INCROOT}/Tools/ITool.hpp
    ${INCROOT}/Tools/Pen.hpp
  PRIVATE
    ToolManager.cpp
    Tools/Pen.cpp
  )

target_link_libraries(YAGE-ToolManager
  PUBLIC
    ShishGL
    YAGE-PropertyManager
  )

add_subdirectory(Tools)