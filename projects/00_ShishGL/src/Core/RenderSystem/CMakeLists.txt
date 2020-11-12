add_library(ShishGL-RenderSystem)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/RenderSystem)

target_include_directories(ShishGL-RenderSystem
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-RenderSystem
  PUBLIC
    ${INCROOT}/GraphicObject.hpp
    ${INCROOT}/LayoutManager.hpp
    ${INCROOT}/RenderSystem.hpp
  PRIVATE
    GraphicObject.cpp
    LayoutManager.cpp
    RenderSystem.cpp
  )

target_link_libraries(ShishGL-RenderSystem
  PUBLIC
    ShishGL-LogSystem
    ShishGL-EventSystem
    ShishGL-Platform
  )