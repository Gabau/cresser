/**
 * @file parser.h
 * @author Gabriel Au (au.gabriel@yahoo.com.sg)
 * @brief File for parsing arguments.
 * @version 0.1
 * @date 2021-12-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "hashtable.h"

using std::string;
using std::vector;
using ht::hashtable;

const string DUPLICATE_ARGUMENT = "Option has been called twice.";
const string DUPLICATE_PREFIX = "Multiple prefixes used.";
const string PREFIX_NOT_IN_STRING = "Prefix is not in string.";


struct duplicate_argument_exception : public exception {
  virtual const char* what() const throw() {
    return DUPLICATE_ARGUMENT.c_str();
  }
};

struct duplicate_prefix_exception : public exception {
  virtual const char* what() const throw() {
    return DUPLICATE_PREFIX.c_str();
  }
};




namespace parser {
  struct prefix {
    prefix() {this->name = "";}
    prefix(string name) {this->name = name;}
    string name;
    int hash(int maxvalue);
    friend bool operator==(const prefix &lhs, const prefix &rhs) {
      return lhs.name.compare(rhs.name) == 0;
    }
  };

  /**
   * @brief Takes in a group of prefixes and the tokens, 
   * and outputs the
   * index that the prefix is at, when particular prefix is queried.
   * 
   */
  class argument_multimap {
   public:
    // constructor.
    argument_multimap(char** tokens, int count,
       vector<prefix> prefixes);
    // Returns the index within tokens, where the prefix is found.
    int query(prefix arg);
    // Obtains the argument multimap from tokens as a string, space seperated.
    static argument_multimap of(string tokens, vector<prefix> prefixes);
   private:
    hashtable<prefix, int> table;
    vector<prefix> prefixes;
  };

}

#endif