/* Created by Ghost Gloomy on 2018/11/8. */

#include <string.h>
#include <algorithm>
#include "LabelStrings.h"
#include "util_log.h"
#include "Deleter.h"

namespace sinsy
{

/*!
 constructor
 */
LabelStrings::LabelStrings()
{
}

/*!
 destructor
 */
LabelStrings::~LabelStrings()
{
   std::for_each(stringList.begin(), stringList.end(), ArrayDeleter<char>());
}

/*!
 get size
 */
size_t LabelStrings::size() const
{
   return stringList.size();
}

/*!
 get data
 */
const char* const * LabelStrings::getData() const
{
   return &stringList[0];
}

/*!
 output label
 */
void LabelStrings::output(const std::string& str)
{
   size_t sz(str.size());

   char* lab(new char[sz + 1]);
   strcpy(lab, str.c_str());
   stringList.push_back(lab);
}

};  // namespace sinsy
