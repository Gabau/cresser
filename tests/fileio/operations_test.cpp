/**
 * @file operations_test.cpp
 * @author Gabau (au.gabriel@yahoo.com.sg)
 * @brief Test for operations.h
 * @version 0.1
 * @date 2021-12-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "operations.h"
#include "lz77encoder.h"


int test_rdfile(string);
int test_wrfile(string);
int main() {
  string test = "MKMKMASMKKf makdmkm dm mkmkds fmskd mkdsmf kal"
    "jlf nsnmfkmlkfm ksdlfm alsmdflkm sdkmflksmdklf dlsk fmdslk mdls fmld s";
  test = lz77_encode(test);
  test_wrfile(test);
  return test_rdfile(test);
}

int test_wrfile(string test) {
  wrto("testfile", test);
  return 0;
}

int test_rdfile(string test) {
  string res = rfrom("testfile");
  if (res.compare(test) != 0) {
    cout << "String different: " << endl;
    cout << "out: " << res << endl;
    cout << "In: " << test;
    return -1;
  }
  return 0;
}
