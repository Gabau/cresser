add_executable(hashtable_test hashtable_test.cpp)

target_link_libraries(hashtable_test Parser)

add_test(hashtable_test hashtable_test)


add_executable(argument_multimap_test argument_multimap_test.cpp)

target_link_libraries(argument_multimap_test Parser)

function(do_test target arg1 arg2 arg3 result)
  add_test(NAME argument_map_test${arg} COMMAND ${target} ${arg1} ${arg2} ${arg3})
  set_tests_properties(argument_map_test${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

do_test(argument_multimap_test "-p" "-l" "-r" "-p\n-l\ninval\n-r\n")
# add_test(argument_multimap_test argument_multimap_test)