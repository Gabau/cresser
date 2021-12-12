# Folder containing files related to encoding bit information

add_library(Encode encoder.cpp lz77encoder.cpp)

target_include_directories(Encode 
  INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
)