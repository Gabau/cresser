add_library(Files operations.cpp)

# Usage requirements
target_include_directories(Files
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)