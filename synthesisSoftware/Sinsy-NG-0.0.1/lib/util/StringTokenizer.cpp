/* Created by Ghost Gloomy on 2018/11/8. */

#include "StringTokenizer.h"
#include "util_log.h"

namespace sinsy
{

/*!
 constructor
 */
StringTokenizer::StringTokenizer(const std::string& str, const std::string& separator)
{
   size_t start(0);
   size_t end(0);
   size_t size(str.size());
   while (start < size) {
      end = str.find_first_of(separator, start);
      if (end == std::string::npos) {
         end = size;
      }
      if (start != end) {
         values.push_back(str.substr(start, end - start));
      }
      start = end + 1;
   }
}

/*!
 destructor
 */
StringTokenizer::~StringTokenizer()
{
}

/*!
 access at element of idx
 */
std::string StringTokenizer::at(size_t idx) const
{
   return values.at(idx);
}

/*!
 get size
 */
size_t StringTokenizer::size() const
{
   return values.size();
}

};  // namespace sinsy
