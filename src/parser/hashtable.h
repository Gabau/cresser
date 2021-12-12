/**
 * @file hashtable.h
 * @author Gabriel Au (au.gabriel@yahoo.com.sg)
 * @brief Implementation of a hashtable.
 * @version 0.1
 * @date 2021-12-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H



#include <stdlib.h>
#include <utility>
#include <vector>
#include <exception>
#include <string>


using std::pair;
using std::vector;
using std::exception;
using std::string;






namespace ht {

  struct hash_table_exception : public exception {
    hash_table_exception(string msg) {
      this->msg = msg;
    }
    string msg;
    virtual const char* what() const throw() {
      return msg.c_str();
    }
  };

  template <typename K, typename V>
  class opt_pair {
   public:
    opt_pair() {}
    virtual K first() {
      throw hash_table_exception("Invalid access of pair");
    }
    virtual V second() {
      throw hash_table_exception("Invalid access of pair");
    }
    virtual bool isEmpty() {return true;};
  };


  template <typename K, typename V>
  class hashed_pair : public opt_pair<K, V> {
  public:
    hashed_pair(K first, V second) {
      this->head = first; 
      this->tail = second;
    }

    bool isEmpty() override {return false;};

    virtual K first() override {
      return this->head;
    }
    virtual V second() override {
      return this->tail;
    }

  private:
    K head;
    V tail;
    
  };





  /**
   * @brief Implementation of hashtable using linear chaining.
   *        IMPT: remove is not implemented as it is not needed.
   * 
   * @tparam K has to have method hash(int maxsize) that returns a hash
   *         that accomodates for the hashtable size.
   * @tparam V 
   */
  template <typename K, typename V>
  class hashtable {
  public:
    hashtable();
    virtual ~hashtable() {free(array);}
    void add(K key, V value);
    V search(K key);
    // not implemented
    // void remove(K key);
  private: 
    vector<hashed_pair<K, V>*> all_elements;
    opt_pair<K, V>** array;
    size_t maxsize;
    size_t size;
  };

// Implementation, do not look pass this point.

  template <typename K, typename V>
  hashtable<K, V>::hashtable() {
    maxsize = 10;  // initialise max size to 10
    size = 0;  // initialise size to 0
    array = new opt_pair<K, V>*[maxsize];
    for (int i = 0; i < maxsize; i++) {
      array[i] = new opt_pair<K, V>();
    }
  }






  template <typename K, typename V>
  void hashtable<K, V>::add(K key, V value) {
    hashed_pair<K, V>* toAdd = new hashed_pair<K, V>(key, value);
    size++;
    if (size > maxsize * 3 / 4) {
      // note that the non empty references
      // are still being used within all_elements.
      // They do not need to be deleted.
      for (int i = 0; i < maxsize; i++) {
        if (array[i]->isEmpty()) {
          delete array[i];
        }
      }
      delete[] array;
      size = 1;
      
      array = new opt_pair<K, V>*[maxsize * 2];
      this->maxsize = maxsize * 2;
      for (int i = 0; i < maxsize; i++) {
        array[i] = new opt_pair<K, V>();
      }
      for (opt_pair<K, V>* element : all_elements) {
        if (element->isEmpty()) {
          continue;
        }
        int hash = element->first().hash(maxsize) % maxsize;  
        // extra modulo just in case
        for (int i = 0; i < maxsize; i++) {
          int address = (i + hash) % maxsize;
          if (array[address]->isEmpty()) {
            // Entry can be used
            array[address] = element;
            break;
          }
          if (array[address]->first() == key) {
            //when the key has been logged
            throw hash_table_exception("Key has been logged before.");
          }
        }
      }
    }
    all_elements.push_back(toAdd);

    int hash = key.hash(maxsize) % maxsize;  // extra modulo just in case
    for (int i = 0; i < maxsize; i++) {
      int address = (i + hash) % maxsize;
      if (array[address]->isEmpty()) {
        // Entry can be used
        array[address] = toAdd;
        return;
      }
      if (array[address]->first() == key) {
        //when the key has been logged
        throw hash_table_exception("Key has been logged before.");
      }
    }
    // not possible to reach
  }

  template <typename K, typename V>
  V hashtable<K, V>::search(K key) {
    int val = key.hash(maxsize) % maxsize;
    for (int i = 0; i < maxsize; i++) {
      if (array[i + val]->isEmpty()) {
        throw hash_table_exception("Key has not been logged before");
      }
      if (array[i + val]->first() == key) {
        return array[i + val]->second();
      }
    }
    throw hash_table_exception("Key has not been logged before");
  }


}






#endif
