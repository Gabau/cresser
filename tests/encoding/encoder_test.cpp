/**
 * @file encoder_test.cpp
 * @author Gabau (au.gabriel@yahoo.com.sg)
 * @brief Tests for encoder.h.
 * @version 0.1
 * @date 2021-12-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "encoder.h"

bool equals(char*, char*, size_t size1, size_t size2);

int main() {
  encoder* en = encoder::of();
  string test = "Hello world";
  string result = en->decode(en->encode(test));
  if (test.compare(result) != 0) {
    return -1;
  }
  return 0;
}
