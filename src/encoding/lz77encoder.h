/**
 * @file lz77encoder.h
 * @author your name (you@domain.com)
 * @brief Header file for encoding information in lz77
 * @version 0.1
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef LZ77_ENCODER_H
#define LZ77_ENCODER_H

#include <iostream>

using namespace std;



//attempt to implement lz77 compression for character based compression
class lz77_encoding_t {
  public: 
    lz77_encoding_t(char, uint16_t, uint16_t);
    static lz77_encoding_t from_string(string, string);
    //creates a string to write
    string toWrite();
    //obtain the length of the prefix
    size_t length() {return this->size_of_prefix;}
    u_int16_t ld;
    u_int16_t size_of_prefix;
    u_int16_t offset;

  private: 
    //end char
    char val;
    //variable to store 
    //offset in first 12 bits, size of prefix in last 4 bits
    
};


/**
 * @brief Function to split a 16bit value into
 * two 8 bit characters
 * 
 * @return char* of length two.
 */
string split(uint16_t);

/**
 * @brief Takes in a string of length two and combines it into an integer of length 16 bits.
 * 
 * @return uint16_t 
 */
uint16_t combine(string);



//given a string to compress, supposed to output a string through the encoder
string lz77_encode(string);

string lz77_decode(string);




#endif