add_executable(encoder_test encoder_test.cpp)
add_executable(lz77_encoder_test lz77_encoder_test.cpp)

target_link_libraries(lz77_encoder_test PUBLIC Encode)
target_link_libraries(encoder_test PUBLIC Encode)


add_test(lz77_encoder_test lz77_encoder_test)
add_test(encoder_test encoder_test)
