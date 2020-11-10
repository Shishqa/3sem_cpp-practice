add_library(ShishGL INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL)

target_include_directories(ShishGL
  INTERFACE
    ${INCROOT})

add_subdirectory(Core)