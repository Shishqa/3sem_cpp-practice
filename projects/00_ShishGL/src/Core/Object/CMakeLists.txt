add_library(ShishGL-Object)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Object)

target_include_directories(ShishGL-Object
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Object
  PUBLIC
    ${INCROOT}/Object.hpp
    ${INCROOT}/ObjectManager.hpp
  PRIVATE
    Object.cpp
    ObjectManager.cpp
    ${INCROOT}/ObjectManager.ipp
  )

target_compile_features(ShishGL-Object
  PUBLIC
    cxx_std_17
  )
