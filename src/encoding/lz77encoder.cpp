/**
 * @file lz77encoder.cpp
 * @author Gabriel Au (au.gabriel@yahoo.com.sg)
 * @brief Implementation of lz77encoder.h
 * @version 0.1
 * @date 2021-12-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <assert.h>
#include <string>
#include "lz77encoder.h"


using std::string;

const uint16_t MAX_OFFSET = 0xFFF;
const uint16_t MAX_LENGTH = 0xF;



struct bad_int_values : public std::exception {
  const char* what() const throw() {
    return "Bad integer values used for this function. "
      "Not within specification, should be positive and within the bit range.";
  }
};




lz77_encoding_t::lz77_encoding_t(char endChar,
  uint16_t offset,
  uint16_t length) {
  // ensures that the length and offset are positive
  if (length < 0 || offset < 0) {
    throw bad_int_values();
  }
  // check that the values do not exceed the bit range allocated
  // offset is allocated 12 bits and length is allocated
  if (offset > MAX_OFFSET || length > MAX_LENGTH) {
    throw bad_int_values();
  }
  // convert the two integers into uint16 form.
  uint16_t result = (uint16_t) offset;
  result = result << 4;
  result = result | length;
  this->ld = result;
  this->val = endChar;
  this->offset = offset;
  this->size_of_prefix = length;
}

string split(uint16_t input) {
  char first = (input >> 8);
  char second = input;
  string result(2, first);
  result[1] = second;
  assert(combine(result) == input);
  return result;
}

// writing three bytes
string lz77_encoding_t::toWrite() {
  char first = this->val;

  // split the 16bit int to 2 bytes
  string next = split(this->ld);
  return first + next;
}

lz77_encoding_t lz77_encoding_t::from_string(string look_ahead_window,
  string encoded_window) {
  // look for the longest prefix within
  // look_ahead_window that is within encoded_window
  int ptr = 0;
  int string_size = 1;
  string overall = encoded_window + look_ahead_window;
  string prefix = "";
  if (encoded_window.compare("") == 0) {
    return lz77_encoding_t(look_ahead_window[0], 0, 0);
  }
  for (int i = 0; i < look_ahead_window.length(); i++) {
    string totest = prefix;
    // obtain the current prefix
    totest = totest + look_ahead_window[i];
    int val = overall.substr(0, encoded_window.length() + i).find(totest);
    if (val == -1) {
      // handle case when the prefix is only one letter long
      if (totest.length() == 1) {
        return lz77_encoding_t(totest[0], 0, 0);
      }
      if (prefix.length() == 1) {  // short circuit
        return lz77_encoding_t(prefix[0], 0, 0);
      }
      assert(ptr <= encoded_window.length());
      // handle case when the previous prefix is in the sequence
      return lz77_encoding_t(look_ahead_window[i], ptr, prefix.length());
    }
    prefix = totest;
    ptr = encoded_window.length() - val;
    if (prefix.length() == 15) {
      return lz77_encoding_t(look_ahead_window[i + 1], ptr, prefix.length());
    }
  }

  // the entire sequence matches...
  return lz77_encoding_t(look_ahead_window[prefix.length() - 1],
      ptr, prefix.length() - 1);
}

string lz77_encode(string val) {
  // to create the sliding window
  string res = "";
  uint64_t result_ptr = 0;
  uint64_t start = 0;
  uint16_t offset = 0;
  uint16_t length = 0;  // maximum length is 0xF for matching prefix
  // variables to indicate the sliding window size
  uint16_t encoded_buffer = 0;
  uint16_t encoded_buffer_maximum = 2000;
  // maximum offset is 4095
  const uint16_t look_ahead_buffer = 2000;
  for (start = 0; start < val.length(); start++) {
    // from the current start value, we look for a repeated pattern
    // past the encoded buffer
    uint64_t look_ahead_start = start + encoded_buffer;
    // could just use pointer based operations
    string look_ahead_window = val.substr(look_ahead_start, look_ahead_buffer);
    string encoded_window = val.substr(start, encoded_buffer);
    if (look_ahead_window.compare("") == 0) {
      // when there is nothing to look for
      return res;
    }
    lz77_encoding_t token = lz77_encoding_t::from_string(look_ahead_window,
      encoded_window);
    res = res + token.toWrite();
    if (encoded_buffer == encoded_buffer_maximum) {
      // when the buffer region shouldn't be expanded
      start += token.length();
      continue;
    }
    // adjust start to not change, until the encoded buffer has
    // reached a certain value
    encoded_buffer++;
    start--;
    start += token.length();
    
  }

  return res;
}


uint16_t combine(string str) {
  uint16_t ld = str[0];
  uint16_t lower = (uint16_t) str[1];
  lower = lower & 0xFF;  // mask the first 4 bits
  ld = ld << 8;
  ld = ld | lower;
  return ld;
}


string lz77_decode(string val) {
  if (val.compare("") == 0) {
    return "";
  }
  string res = "";
  // goal -- to build from the tokens
  for (int i = 0; i < val.length(); i+=3) {
    // get the token
    string token = val.substr(i, 3);
    // parse the token
    uint16_t ld = combine(token.substr(1, 2));
    uint16_t offset = ld >> 4;
    uint16_t length = ld & 0xF;
    if (offset == 0 && length == 0) {
      res += token[0];
      continue;
    }
    if (offset > res.length()) {
      cout << "Offset " << offset << endl;
      cout << "Length " << length << endl;
      cout << "Result length " << res.length() << endl;
      cout << "First token " << token[0] << endl;
      cout << "Current situation " << res << endl;
      exit(-1);
    }
    // when there is a prefix in the current sliding window.

    int start = res.length() - offset;
    for (int i = start; i < start + length; i++) {
      res += res[i];
    }
    res += token[0];
  }
  return res;
}
