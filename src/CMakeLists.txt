add_subdirectory(fileio)
add_subdirectory(parser)
add_subdirectory(encoding)


add_executable(cresser main.cpp)


target_link_libraries(cresser PUBLIC Files Encode Parser)

target_include_directories(cresser PUBLIC "${PROJECT_BINARY_DIRECTORY}" "${CMAKE_SOURCE_DIRECTORY}")

