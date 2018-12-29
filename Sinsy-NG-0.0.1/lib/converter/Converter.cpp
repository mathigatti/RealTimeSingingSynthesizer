/* Created by Ghost Gloomy on 2018/11/8. */

#include <algorithm>
#include <exception>
#include <stdexcept>
#include "Converter.h"
#include "IConvertable.h"
#include "ConfGroup.h"
#include "util_log.h"
#include "util_converter.h"
#include "Deleter.h"

namespace sinsy
{

namespace
{

/*!
 convert resets
*/
void convertRests(IConf::ConvertableList::iterator begin, IConf::ConvertableList::iterator end, const std::string& silStr)
{
   if (begin == end) {
      return;
   }

   IConf::ConvertableList::iterator itr(begin);
   for (; itr != end; ++itr) {
      IConvertable& convertable(**itr);
      if (convertable.isRest() && !convertable.isConverted()) {
         std::vector<PhonemeInfo> phonemes;
         std::string restType(PhonemeInfo::TYPE_SILENT);
         std::string restStr(silStr);

         if (begin != itr) { // not head
            if (!(*(itr - 1))->isRest()) { // prev note is not rest
               restStr = DEFAULT_PAU_STR;
               restType = PhonemeInfo::TYPE_PAUSE;
            }
         }
         if (end - 1 != itr) { // not tail
            if (!(*(itr + 1))->isRest()) { // prev note is not rest
               restStr = DEFAULT_PAU_STR;
               restType = PhonemeInfo::TYPE_PAUSE;
            }
         }
         phonemes.push_back(PhonemeInfo(restType, restStr));
         convertable.addInfo(phonemes);
      }
   }
}
};

/*!
 constructor
*/
Converter::Converter()
{
}

/*!
 destructor
*/
Converter::~Converter()
{
   clear();
}

/*!
 clear
*/
void Converter::clear()
{
   confs.clear();
}

/*!
 set confs to converter
 */
bool Converter::setLanguages(const std::string& languages, const std::string& dirPath)
{
   return confManager.setLanguages(languages, dirPath);
}

/*!
 get sil string
 */
std::string Converter::getSilStr() const
{
   if (!confs.empty()) {
      return confs.front()->getSilStr();
   }
   return DEFAULT_SIL_STR;
}

/*!
 convert
*/
bool Converter::convert(const std::string& enc, IConf::ConvertableList::iterator begin, IConf::ConvertableList::iterator end) const
{
   // convert rests
   convertRests(begin, end, this->getSilStr());

   // convert pitches
   ConfGroup confs;
   confManager.setDefaultConfs(confs);
   IConf::ConvertableList::iterator b(begin);
   while (end != b) {
      IConvertable& bConv(**b);
      if (bConv.isConverted()) {
         ++b;
         continue;
      }

      IConf::ConvertableList::iterator e(b);
      for (++e; end != e; ++e) {
         IConvertable& eConv(**e);
         if (eConv.isConverted()) {
            confs.convert(enc, b, e);
            b = e + 1;
            break;
         }
      }
      if (end == e) {
         confs.convert(enc, b, e);
         b = e;
      }
   }

   return true;
}

};  // namespace sinsy
