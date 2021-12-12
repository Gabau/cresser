#include <vector>
#include <cstdarg>
#include <exception>
#include "parser.h"



using parser::argument_multimap;
using parser::prefix;
using std::vector;
using std::exception;





argument_multimap::argument_multimap(char** tokens, int count,
  vector<prefix> prefixes) {
  this->prefixes = prefixes;
  for (int i = 0; i < count; i++) {
    int check = 0;
    string val(*tokens);
    for (prefix pf : prefixes) {
      if (pf.name.compare(val) == 0) {
        check++;
        try {
          table.add(pf, i);
        } catch(ht::hash_table_exception) {
          // when there is a dublicate key --> which is the only
          // exception thrown by this function
          throw duplicate_argument_exception();
        }
      }
      if (check > 1) {
        throw duplicate_prefix_exception();
      }
    }
    tokens++;
  }


}

int argument_multimap::query(prefix arg) {
  try { 
    return table.search(arg);
  } catch (ht::hash_table_exception e) {
    // when the prefix is not in the set
    return -1;
  }
}



int prefix::hash(int maxvalue) {
  //hash based on characters
  int res = 0;
  for (int i = 0; i < this->name.length(); i++) {
    res = res | name[i];
    res = res << 5;
  }
  return res % maxvalue;
}





