/**
 * @file encoder.cpp
 * @author Gabau (au.gabriel@yahoo.com.sg)
 * @brief 
 * @version 0.1
 * @date 2021-12-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "encoder.h"
#include <string>

// simple implementation of an encoder
class simple_encoder : public encoder {
 public:
  simple_encoder() : encoder() {}
  string encode(string);
  string decode(string);
};



string simple_encoder::encode(string input) {
  return input;
}

string simple_encoder::decode(string input) {
  return input;
}


encoder* encoder::of() {
  return new simple_encoder();
}

encoder::encoder() { }










