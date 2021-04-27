add_subdirectory(gcem)
add_subdirectory(pybind11)

# Stats library
add_library(stats INTERFACE)
target_include_directories(stats INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/stats/include)
