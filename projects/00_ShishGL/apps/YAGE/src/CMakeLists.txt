add_executable(yage)

set(INCROOT ${YAGE_SOURCE_DIR}/include/YAGE)

target_include_directories(yage
  PUBLIC
    ${INCROOT}
  )

target_sources(yage
  PUBLIC
    ${INCROOT}/YAGE.hpp
    ${INCROOT}/Canvas.hpp
  PRIVATE
    main.cpp
    YAGE.cpp
    Canvas.cpp
  )

target_link_libraries(yage
  PUBLIC
    ShishGL
    YAGE-ToolManager
  )

add_subdirectory(ToolManager)
add_subdirectory(PropertyManager)