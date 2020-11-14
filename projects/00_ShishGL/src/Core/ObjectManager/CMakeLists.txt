add_library(ShishGL-ObjectManager)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/ObjectManager)

target_include_directories(ShishGL-ObjectManager
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-ObjectManager
  PUBLIC
    ${INCROOT}/Object.hpp
    ${INCROOT}/ObjectManager.hpp
  PRIVATE
    ${INCROOT}/ObjectManager.ipp
    Object.cpp
    ObjectManager.cpp
  )

target_compile_features(ShishGL-ObjectManager
  PUBLIC
    cxx_std_17
  )

target_link_libraries(ShishGL-ObjectManager
  PUBLIC
    ShishGL-LogSystem
  )