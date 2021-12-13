cmake_minimum_required(VERSION 3.0.0)
set(CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

project(cresser VERSION 0.1.0)



# Function to add a text file from resources to current cmake directory
function(add_text_file filename)
  file(COPY "${CMAKE_SOURCE_DIR}/resources/text/${filename}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
endfunction()


if (CMAKE_COMPILER_IS_GNUCXX)
  include(CodeCoverage)
  append_coverage_compiler_flags()
  setup_target_for_coverage_lcov(NAME cresser_coverage EXECUTABLE ctest EXCLUDE "/usr/include/*" "${CMAKE_SOURCE_DIR}/tests")
endif()
include(CTest)
enable_testing()



add_subdirectory(src)



list(APPEND EXTRA_LIBS Files Encode)


install(TARGETS cresser DESTINATION bin)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)


add_subdirectory(tests)
