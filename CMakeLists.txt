cmake_minimum_required(VERSION 3.0.0)
set(CXX_STANDARD 20)

project(cresser VERSION 0.1.0)

include(CTest)
enable_testing()



add_subdirectory(src)
add_subdirectory(tests)


list(APPEND EXTRA_LIBS Files Encode)


install(TARGETS cresser DESTINATION bin)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)


