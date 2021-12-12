/**
 * @file encoder.h
 * @author your name (you@domain.com)
 * @brief Header describing functions used to encode the information.
 * @version 0.1
 * @date 2021-12-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ENCODER_H
#define ENCODER_H
#include <iostream>

using namespace std;

/**
 * @brief Virtual class representing something used to encode information passed in as chars. Default implementation does nothing.
 * 
 */
class encoder {
  public:
    encoder();
    virtual string encode(string) = 0;
    virtual string decode(string) = 0;
    static encoder* of();
};


#endif




