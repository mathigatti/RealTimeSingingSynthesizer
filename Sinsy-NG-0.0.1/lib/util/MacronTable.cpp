/* Created by Ghost Gloomy on 2018/11/8. */

#include <fstream>
#include "MacronTable.h"
#include "StringTokenizer.h"
#include "util_log.h"
#include "util_string.h"

namespace sinsy
{

namespace
{
const std::string MACRON_DELIMITER = ",";

/*!
 extract phoneme list from string
 */
void extractPhonemeList(const std::string& str, MacronTable::PhonemeList& pl)
{
   StringTokenizer st(str, MACRON_DELIMITER);
   size_t sz(st.size());
   pl.resize(sz);
   for (size_t i(0); i < sz; ++i) {
      pl[i] = st.at(i);
   }
}

};

/*!
 constructor
*/
MacronTable::MacronTable()
{
}

/*!
 destructor
*/
MacronTable::~MacronTable()
{
   clear();
}

/*!
 clear
*/
void MacronTable::clear()
{
   const ConvertTable::iterator itrEnd(convertTable.end());
   ConvertTable::iterator itr(convertTable.begin());
   for (; itrEnd != itr; ++itr) {
      delete itr->second;
   }
   convertTable.clear();
}

/*!
 read from file

 If the file is not exist, output warning message and return true.

 @param fname phoneme table file path
 @param return true if success
 */
bool MacronTable::read(const std::string& fname)
{
   std::ifstream ifs(fname.c_str());
   if (!ifs) {
      WARN_MSG("Cannot open macron table file : " << fname);
      return true;
   }

   clear();

   std::string buffer;

   while (!ifs.eof()) {
      std::getline(ifs, buffer);
      StringTokenizer st(buffer, BLANK_STR);

      size_t sz(st.size());
      if (0 == sz) {
         continue;
      } else if (3 != sz) {
         ERR_MSG("Wrong macron table (" << buffer << ") : " << fname);
         return false;
      }

      // src
      PhonemeList pl;
      extractPhonemeList(st.at(0), pl);

      // dst
      Result* result(new Result);
      extractPhonemeList(st.at(1), result->forward);
      extractPhonemeList(st.at(2), result->backward);

      if (false == convertTable.insert(std::make_pair/*<std::vector<std::string>, Result*>*/(pl, result)).second) {
         ERR_MSG("Wrong macron table (There is a duplication : " << st.at(0) << ") : " << fname);
         delete result;
         return false;
      }
   }

   return true;
}

/*!
 divide phoneme set
 */
bool MacronTable::divide(const PhonemeList& src_, PhonemeList& dst1, PhonemeList& dst2) const
{
   PhonemeList src(src_);
   dst1.clear();
   dst2.clear();
   while (!src.empty()) {
      ConvertTable::const_iterator itr(convertTable.find(src));
      if (convertTable.end() != itr) {
         dst1.insert(dst1.end(), itr->second->forward.begin(), itr->second->forward.end());
         dst2 = itr->second->backward;
         return true;
      }
      dst1.push_back(src.front());
      src.erase(src.begin());
   }
   dst1.clear();
   return false;
}

};  // namespace sinsy
