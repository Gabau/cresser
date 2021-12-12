/**
 * @file operations.cpp
 * @author Gabriel Au (au.gabriel@yahoo.com.sg)
 * @brief Common operations performed on the file system.
 * @version 0.1
 * @date 2021-12-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <fstream>
#include <streambuf>
#include <vector>
#include <numeric>
#include <string>
#include <filesystem>
#include "operations.h"

using std::string;



string rfrom(string pathname) {
  string result = "";
  ifstream input(pathname, ios::binary);
  std::vector<char> buffer(std::istreambuf_iterator<char>(input), {});
  string res = accumulate(buffer.begin(), buffer.end(), result);
  input.close();
  return res;
}

void wrto(string pathname, string value) {
  ofstream file;
  file.open(pathname, ios::binary);
  if (file.is_open()) {
    file << value;
  }
  file.close();
}
