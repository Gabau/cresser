/**
 * @file operations.h
 * @author your name (you@domain.com)
 * @brief Header file containing utility functions for file operations.
 * @version 0.1
 * @date 2021-12-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

using namespace std;


/**
 * @brief Read from the given path
 * 
 * @param pathname 
 * @return string 
 */
string rfrom(string pathname);


/**
 * @brief Write to the given path with the given string.
 * 
 * @param pathname 
 * @param towrite 
 */
void wrto(string pathname, string towrite);


/**
 * @brief Reads from the given directory, and encodes it into a 
 * string.
 * 
 * @param pathname 
 * @return string 
 */
string read_directory(string pathname);



/**
 * @brief Reads from the given encoded string and generates the directory
 * in the given path.
 * 
 * @param encoded 
 * @param location 
 */
void wr_directory(string encoded, string location);