/* Created by Ghost Gloomy on 2018/11/8. */

#include "util_log.h"
#include "util_string.h"
#include "StringTokenizer.h"
#include "MultibyteCharRange.h"

namespace sinsy
{

/*!
 constructor
 */
MultibyteCharRange::MultibyteCharRange()
{
}

/*!
 destructor
 */
MultibyteCharRange::~MultibyteCharRange()
{
}

/*!
 add multibyte char range
 */
bool MultibyteCharRange::addRange(size_t sz, unsigned char b, unsigned char e)
{
   if (sz <= 0) {
      ERR_MSG("Multibyte char size is set to zero");
      return false;
   }
   if (e < b) {
      unsigned char tmp = b;
      b = e;
      e = tmp;
   }

   // check overlapping
   const RangeList::const_iterator itrEnd(rangeList.end());
   RangeList::const_iterator itr(rangeList.begin());
   for (; itrEnd != itr; ++itr) {
      if ((itr->begin <= b && b <= itr->end) || (itr->begin <= e && e <= itr->end)) {
         ERR_MSG("Multibyte char ranges are overlapped");
         return false;
      }
   }

   // add
   rangeList.push_back(Range(sz, b, e));

   return true;
}

/*!
 get char size (if 1 or unknown, return 1)
 */
size_t MultibyteCharRange::getCharSize(unsigned char firstChar) const
{
   const RangeList::const_iterator itrEnd(rangeList.end());
   RangeList::const_iterator itr(rangeList.begin());
   for (; itrEnd != itr; ++itr) {
      if (itr->begin <= firstChar && firstChar <= itr->end) {
         return itr->size;
      }
   }

   return 1;
}

};  // namespace sinsy
