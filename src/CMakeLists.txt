add_subdirectory(fileio)
add_subdirectory(parser)
add_subdirectory(encoding)


add_executable(cresser main.cpp)


target_link_libraries(cresser PUBLIC Files Encode Parser)

target_include_directories(cresser PUBLIC "${PROJECT_BINARY_DIRECTORY}" "${CMAKE_SOURCE_DIRECTORY}")


add_text_file(BIG_TEST.txt)

add_test(cresser_test_encode ./cresser BIG_TEST.txt -o out)
add_test(cresser_test_decode ./cresser out -o out -d)
add_test(compare_test diff BIG_TEST.txt out)

set_property(TEST cresser_test_decode APPEND PROPERTY DEPENDS cresser_test_encode)
set_property(TEST compare_test APPEND PROPERTY DEPENDS cresser_test_decode)


add_text_file(SMALL_TEST.txt)

add_test(cresser_small_test_encode ./cresser SMALL_TEST.txt -o out)
add_test(cresser_small_test_decode ./cresser out -o out -d)
add_test(compare_test_small diff SMALL_TEST.txt out)

set_property(TEST cresser_small_test_decode APPEND PROPERTY DEPENDS cresser_small_test_encode)
set_property(TEST compare_test_small APPEND PROPERTY DEPENDS cresser_small_test_decode)
