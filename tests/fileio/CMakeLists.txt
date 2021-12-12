add_executable(operations_test operations_test.cpp)

target_link_libraries(operations_test PUBLIC Files Encode)

add_test(operations_test operations_test)

