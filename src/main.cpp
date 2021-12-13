/**
 * @file main.cpp
 * @author Gabriel (au.gabriel@yahoo.com.sg)
 * @brief Main running code for the program.
 * @version 0.1
 * @date 2021-12-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <string.h>
#include <iostream>
#include <vector>
#include "operations.h"
#include "lz77encoder.h"
#include "parser.h"


using std::string;
using parser::prefix;
using parser::argument_multimap;
using std::vector;

const prefix DECODE("-d");
const prefix DECODE_ALT("--decode");
const prefix OUTPUT("-o");
vector<prefix> prefixes{DECODE, DECODE_ALT, OUTPUT};

void help_message();

/**
 * @brief cresser [input_file] [-o output_file] [--decode | -d]
 * When --decode is present, the file is decoded, when it is not present
 * it is assumed that the file should be encoded.
 */
int main(int argc, char** argv) {
  
  // insufficient arguments
  if (argc == 1) {
    help_message();
    return -1;
  }
  
  string inputfile = argv[1];

  argument_multimap arguments(argv, argc, prefixes);
  // input filename

  string filename = "default";
  int decode = arguments.query(DECODE);
  int decode_alt = arguments.query(DECODE_ALT);
  int val = arguments.query(OUTPUT); 
  if (val != -1) {
    filename = string(argv[val + 1]);
  }
  if (decode == -1 && decode_alt == -1) {
    //perform encoding of the input file
    string to_encode = rfrom(inputfile);
    wrto(filename, lz77_encode(to_encode));
  } else {
    string to_decode = rfrom(inputfile);
    wrto(filename, lz77_decode(to_decode));
  }
  
  return 0;
}

void help_message() {
  std::cout << "Under implementation" << std::endl;;
}