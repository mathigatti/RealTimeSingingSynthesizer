/* Created by Ghost Gloomy on 2018/11/8. */

#include <stdexcept>
#include <algorithm>
#include "util_log.h"
#include "util_converter.h"
#include "ConfGroup.h"
#include "Deleter.h"

namespace sinsy
{

/*!
 constructor
 */
ConfGroup::ConfGroup()
{
}

/*!
 destructor
*/
ConfGroup::~ConfGroup()
{
   clear();
}

/*!
 clear all confs
*/
void ConfGroup::clear()
{
   confs.clear();
}

/*!
 convert lyrics to phonemes
*/
bool ConfGroup::convert(const std::string& enc, ConvertableList::iterator begin, ConvertableList::iterator end) const
{
   const ConfList::const_iterator itrEnd(confs.end());
   for (ConfList::const_iterator itr(confs.begin()); itrEnd != itr; ++itr) {
      ConvertableList::iterator b(begin);
      for (ConvertableList::iterator e(b); end != b; ++e) {
         if ((end == e) || (*e)->isConverted()) {
            if (b == e) { // skip
               ++b;
            } else {
               (*itr)->convert(enc, b, e);
               b = e;
            }
            if (end == e) break;
         }
      }
   }
   return true;
}

/*!
 add config
 */
void ConfGroup::add(const IConf* conf)
{
   if (NULL == conf) {
      std::runtime_error("ConfGroup::addConf() NULL pointer");
   }
   confs.push_back(conf);
}

/*!
 get sil string
 */
std::string ConfGroup::getSilStr() const
{
   if (!confs.empty()) {
      return confs.front()->getSilStr();
   }
   return DEFAULT_SIL_STR;
}

};  // namespace sinsy
