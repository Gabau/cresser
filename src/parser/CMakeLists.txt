add_library(Parser parser.cpp)

# Usage requirements
target_include_directories(Parser
  INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
)