# Folder containing files related to encoding bit information

add_library(Encode lz77encoder.cpp)

target_include_directories(Encode 
  INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
)