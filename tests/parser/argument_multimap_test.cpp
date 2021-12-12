#include <vector>
#include <iostream>
#include "parser.h"

using parser::prefix;
using parser::argument_multimap;
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
  vector<prefix> prefixes{prefix("-p"), prefix("-l"),
     prefix("-m"), prefix("-r")};
  argument_multimap mapper(argv, argc, prefixes);
  for (prefix pf : prefixes) {
    int val;
    
    val = mapper.query(pf);
    

    if (val == -1) {
      cout << "inval" << endl;
    } else {
      cout << argv[mapper.query(pf)] << endl;
    }
  }
  return 0;
}