/* Created by Ghost Gloomy on 2018/11/8. */

#include <algorithm>
#include "util_string.h"

namespace sinsy
{

/*!
 c is blank character or not
 */
bool isBlank(char c)
{
   size_t idx(BLANK_STR.find(c));
   if (std::string::npos == idx) {
      return false;
   }
   return true;
}

/*!
 cut left and right blanks
 */
std::string& cutBlanks(std::string& str)
{
   size_t start(str.find_first_not_of(BLANK_STR));
   if (std::string::npos == start) {
      str.clear();
      return str;
   }
   size_t end(str.find_last_not_of(BLANK_STR));
   size_t sz(end - start + 1);
   if ((0 == start) && (str.size() == sz)) {
      return str;
   }
   str = str.substr(start, sz);
   return str;
}

/*!
 find first blank character
 */
size_t findFirstOfBlank(const std::string& str)
{
   return str.find_first_of(BLANK_STR);
}

/*!
 find first not blank character
 */
size_t findFirstNotOfBlank(const std::string& str, size_t index)
{
   return str.find_first_not_of(BLANK_STR, index);
}

/*!
 convert str to lower-case
 */
void toLower(std::string& str)
{
   std::transform(str.begin(), str.end(), str.begin(), tolower);
}

/*!
 convert str to lower-case
 */
void toUpper(std::string& str)
{
   std::transform(str.begin(), str.end(), str.begin(), toupper);
}

};  // namespace sinsy
