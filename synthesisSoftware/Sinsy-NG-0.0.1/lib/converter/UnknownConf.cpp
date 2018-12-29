/* Created by Ghost Gloomy on 2018/11/8. */

#include <algorithm>
#include <exception>
#include <stdexcept>
#include "util_log.h"
#include "util_converter.h"
#include "UnknownConf.h"
#include "IConvertable.h"

namespace sinsy
{

namespace
{
const std::string SIL_STR = "sil";
const std::string LANGUAGE_INFO = "";
const std::string UNKNOWN_PHONEME = "xx";
};

/*!
 constructor
 */
UnknownConf::UnknownConf()
{
}

/*!
 destructor
*/
UnknownConf::~UnknownConf()
{
}

/*!
 clear
 */
void UnknownConf::clear()
{
}

/*!
 convert lyrics to phonemes

 @param enc encoding
 @param begin start of note list
 @param end last of note list
 @return if success, return true
*/
bool UnknownConf::convert(const std::string& enc, ConvertableList::iterator begin, ConvertableList::iterator end) const
{
   IConf::ConvertableList::iterator itr(begin);
   for (; itr != end; ++itr) {
      IConvertable& convertable(**itr);
      if (!convertable.isConverted()) {
         std::string lyric(convertable.getLyric());

         ScoreFlag flag(analyzeScoreFlags(lyric));

         std::vector<PhonemeInfo> phonemes;
         phonemes.push_back(PhonemeInfo("", UNKNOWN_PHONEME, flag));
         convertable.addInfo(phonemes, LANGUAGE_INFO, "");
      }
   }
   return true;
}

/*!
 get sil str

 return edge rest
 */
std::string UnknownConf::getSilStr() const
{
   return SIL_STR;
}

};  // namespace sinsy
