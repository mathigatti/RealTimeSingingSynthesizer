/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_UTIL_STRING_H_
#define SINSY_UTIL_STRING_H_

#include <string>
#include "util_types.h"

namespace sinsy
{
const std::string BLANK_STR = " \t\r\n";
const std::string NULL_STR = "";

//! c is blank character or not
bool isBlank(char c);

//! cut left and right blanks
std::string& cutBlanks(std::string& str);

//! find first blank character
size_t findFirstOfBlank(const std::string& str);

//! find first not blank character
size_t findFirstNotOfBlank(const std::string& str, size_t index);

//! convert str to lower-case
void toLower(std::string& str);

//! convert str to upper-case
void toUpper(std::string& str);

};

#endif // SINSY_UTIL_STRING_H_
