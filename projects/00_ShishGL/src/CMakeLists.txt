add_library(ShishGL INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL)

target_include_directories(ShishGL
  INTERFACE
    ${INCROOT})

target_link_libraries(ShishGL
  INTERFACE
    ShishGL-Core
    ShishGL-Graphics
    ShishGL-DebugUtilities
  )

add_subdirectory(Core)
add_subdirectory(Graphics)
add_subdirectory(DebugUtilities)