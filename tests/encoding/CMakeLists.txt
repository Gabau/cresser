add_executable(lz77_encoder_test lz77_encoder_test.cpp)

target_link_libraries(lz77_encoder_test PUBLIC Encode)

add_test(lz77_encoder_test lz77_encoder_test)

