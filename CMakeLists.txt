cmake_minimum_required(VERSION 3.0.0)
set(CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

project(cresser VERSION 0.1.0)

if (CMAKE_COMPILER_IS_GNUCXX)
  include(CodeCoverage)
  append_coverage_compiler_flags()
  setup_target_for_coverage_lcov(NAME cresser_coverage EXECUTABLE ctest EXCLUDE /usr/include/)
endif()
include(CTest)
enable_testing()



add_subdirectory(src)
add_subdirectory(tests)


list(APPEND EXTRA_LIBS Files Encode)


install(TARGETS cresser DESTINATION bin)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)


