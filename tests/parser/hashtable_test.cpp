#include <string>
#include <iostream>
#include "hashtable.h"

#define TEST_SIZE 10
#define BIG_TEST 1000



class val {
 public:
  val() {
    this->value = 0;
  }
  val(int value) {
    this->value = value;
  }
  int value;
  int hash(size_t size) {
    return value % size;
  }
  friend bool operator== (const val &lhs, const val &rhs) {
    return lhs.value == rhs.value;
  }
  // val& operator=(const val& assigned) {
  //   this->value = assigned.value;
  //   return *this;
  // }
};

using std::string;

int test_hashtable_iter(val* values, size_t size);
int test_set[TEST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
string test_strings[TEST_SIZE] = 
    {"one", "two", "three", "four", "five", "six",
      "seven", "eight", "nine", "ten"};

using ht::hashtable;

ht::hashtable<val, string> table;



int test_hashtable(int*, string*, size_t);

int main() {
  
  
  

  val array[BIG_TEST];
  for (int i = 0; i < BIG_TEST; i++) {
    array[i] = val(i);
  }

  return test_hashtable(test_set, test_strings, TEST_SIZE) 
    | test_hashtable_iter(array, BIG_TEST);
}

int test_hashtable(int* values, string* strs, size_t size) {
  for (size_t i = 0; i < size; i++) {
    val toadd(values[i]);
    table.add(toadd, strs[i]);
  }
  for (size_t i = 0; i < size; i++) {
    val tocheck(values[i]);
    if (table.search(tocheck).compare(strs[i]) != 0) {
      return -1;
    }
  }
  return 0;
}

int test_hashtable_iter(val* values, size_t size) {
  hashtable<val, val> table;
  for (size_t i = 0; i < size; i++) {
    table.add(values[i], values[i]);
  } 
  for (size_t i = 0; i < size; i++) {
    if (!(table.search(values[i]) == values[i])) {
      return -1;
    }
  }
  return 0;
}









