add_library(YAGE-PropertyManager)

set(INCROOT ${YAGE_SOURCE_DIR}/include/YAGE/PropertyManager)

target_include_directories(YAGE-PropertyManager
  PUBLIC
    ${INCROOT}
    ${INCROOT}/Properties
  )

target_sources(YAGE-PropertyManager
  PUBLIC
    ${INCROOT}/Properties/Stroke.hpp
  PRIVATE
  Properties/Stroke.cpp
  )

target_link_libraries(YAGE-PropertyManager
  PUBLIC
    ShishGL
  )

add_subdirectory(Properties)