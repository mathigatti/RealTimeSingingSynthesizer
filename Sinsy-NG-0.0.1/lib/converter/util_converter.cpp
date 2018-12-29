/* Created by Ghost Gloomy on 2018/11/8. */
#include "util_converter.h"
#include "util_log.h"
#include "util_string.h"
#include "StringTokenizer.h"
#include "MultibyteCharRange.h"
#include <iomanip>

namespace sinsy
{

namespace
{
const size_t SCORE_FLAG_NUM = 8;
const char SCORE_FLAG_CHARS[SCORE_FLAG_NUM] = {'\0', '\0', '\0', '#', '$', '@', '^', '%'}; // '\0': Not defined
const ScoreFlag SCORE_FLAG_DISABLE = 0x10;
const ScoreFlag SCORE_FLAG_FALSETTO = 0x08;
const ScoreFlag SCORE_FLAGS[SCORE_FLAG_NUM] = {0x80, 0x40, 0x20, SCORE_FLAG_DISABLE, SCORE_FLAG_FALSETTO, 0x04, 0x02, 0x01};
/*!
 find char from str
 */
size_t findChar(std::string& str, char c, const MultibyteCharRange* charRange, size_t startIdx = 0)
{
   size_t sz(str.size());
   size_t idx(startIdx);
   while (idx < sz) {
      if (c == str[idx]) {
         return idx;
      }
      if (charRange) {
         idx += charRange->getCharSize(static_cast<unsigned char>(str[idx]));
      } else {
         ++idx;
      }
   }
   return std::string::npos;
}

ScoreFlag matchScoreFlag(char c)
{
   for (size_t i(0); i < SCORE_FLAG_NUM; ++i) {
      if (SCORE_FLAG_CHARS[i] == c) {
         return SCORE_FLAGS[i];
      }
   }
   return 0x00;
}

}; // namespace

/*!
 analyze score flags
 */
ScoreFlag analyzeScoreFlags(std::string& str, const MultibyteCharRange* charRange)
{
   ScoreFlag ret(0x00);

   size_t idx(0);
   while (idx < str.size()) {
      ScoreFlag f(matchScoreFlag(str[idx]));
      if (0x00 == f) { // not found
         if (charRange) {
            idx += charRange->getCharSize(static_cast<unsigned char>(str[idx]));
         } else {
            ++idx;
         }
      } else { // found
         ret |= f;
         str.erase(idx, 1);
      }
   }
   return ret;
}

std::string restoreScoreFlag(ScoreFlag flag)
{
   if (0 == flag) {
      return std::string();
   }
   std::ostringstream oss;
   for (size_t i(0); i < SCORE_FLAG_NUM; ++i) {
      if (SCORE_FLAGS[i] & flag) {
         oss << SCORE_FLAG_CHARS[i];
      }
   }
   return oss.str();
}

bool isEnableFlag(ScoreFlag flag)
{
   return (0x00 == (SCORE_FLAG_DISABLE & flag));
}

std::string getScoreFlagStr(ScoreFlag flag)
{
   std::ostringstream oss;
   oss << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(flag);
   return oss.str();
}

ScoreFlag& setDisableFlag(ScoreFlag& flag)
{
   flag |= SCORE_FLAG_DISABLE;
   return flag;
}

ScoreFlag& unsetDisableFlag(ScoreFlag& flag)
{
   flag &= ~SCORE_FLAG_DISABLE;
   return flag;
}

ScoreFlag& setFalsettoFlag(ScoreFlag& flag)
{
   flag |= SCORE_FLAG_FALSETTO;
   return flag;
}


};  // namespace sinsy
