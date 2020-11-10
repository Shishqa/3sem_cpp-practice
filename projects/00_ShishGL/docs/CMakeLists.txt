set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

doxygen_add_docs(docs ShishGL/ShishGL.hpp
                 WORKING_DIRECTORY "${ShishGL_SOURCE_DIR}/include")
