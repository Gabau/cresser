add_executable(operations_test operations_test.cpp)

target_link_libraries(operations_test PUBLIC Files Encode)

add_test(operations_test operations_test)


add_text_file(BIG_TEST.txt)
add_executable(read_test read_test.cpp)

target_link_libraries(read_test PUBLIC Files)

add_test(read_test read_test BIG_TEST.txt)