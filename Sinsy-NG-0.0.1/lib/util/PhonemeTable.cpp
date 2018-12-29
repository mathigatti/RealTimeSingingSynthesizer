//
// Created by Ghost Gloomy on 2018/11/8.
//

#include <fstream>
#include "PhonemeTable.h"
#include "StringTokenizer.h"
#include "util_log.h"
#include "util_string.h"

namespace sinsy
{

/*!
 constructor
*/
PhonemeTable::Result::Result() : syllable(NULL), phonemeList(NULL)
{
}

/*!
 constructor
*/
PhonemeTable::Result::Result(const std::string& s, const PhonemeList* p) : syllable(&s), phonemeList(p)
{
}

/*!
 copy constructor
*/
PhonemeTable::Result::Result(const Result& obj) : syllable(obj.syllable), phonemeList(obj.phonemeList)
{
}

/*!
 destructor
*/
PhonemeTable::Result::~Result()
{
}

/*!
 assignment operator
*/
PhonemeTable::Result& PhonemeTable::Result::operator=(const Result & obj)
{
   this->syllable = obj.syllable;
   this->phonemeList = obj.phonemeList;
   return *this;
}

/*!
 return true if this result is valid
*/
bool PhonemeTable::Result::isValid() const
{
   return (NULL != syllable);
}

/*!
 get syllable
*/
const std::string& PhonemeTable::Result::getSyllable() const
{
   return (NULL == syllable) ? NULL_STR : *syllable;
}

/*!
 get phoneme list
*/
const PhonemeTable::PhonemeList* PhonemeTable::Result::getPhonemeList() const
{
   return phonemeList;
}

/*!
 get matched length
*/
size_t PhonemeTable::Result::getMatchedLength() const
{
   return (NULL == syllable) ? 0 : syllable->size();
}

/*!
 constructor
*/
PhonemeTable::PhonemeTable()
{
}

/*!
 destructor
*/
PhonemeTable::~PhonemeTable()
{
   clear();
}

/*!
 clear
*/
void PhonemeTable::clear()
{
   ConvertTable::iterator itr(convertTable.begin());
   ConvertTable::iterator itrEnd(convertTable.end());
   for (; itr != itrEnd; ++itr) {
      delete itr->second;
   }
   convertTable.clear();
}

/*!
 read from file

 @param fname phoneme table file path
 @param return true if success
 */
bool PhonemeTable::read(const std::string& fname)
{
   std::ifstream ifs(fname.c_str());
   if (!ifs) {
      ERR_MSG("Cannot open phoneme table file : " << fname);
      return false;
   }

   clear();

   std::string buffer;

   while (!ifs.eof()) {
      std::getline(ifs, buffer);
      StringTokenizer st(buffer, BLANK_STR);

      size_t sz(st.size());
      if (0 == sz) {
         continue;
      } else if (1 == sz) {
         ERR_MSG("Wrong phoneme table (value is needed after key) : " << fname);
         return false;
      }
      PhonemeList* pl(new PhonemeList);
      pl->reserve(sz - 1);
      for (size_t i(1); i < sz; ++i) {
         pl->push_back(st.at(i));
      }
      if (false == convertTable.insert(std::make_pair/*<std::string, PhonemeList*>*/(st.at(0), pl)).second) {
         ERR_MSG("Wrong phoneme table (some syllables have same name : " << st.at(0) << ") : " << fname);
         delete pl;
         return false;
      }
   }
   return true;
}

/*!
 find from table
 */
PhonemeTable::Result PhonemeTable::find(const std::string& syllable) const
{
   for (size_t sz(syllable.size()); 0 < sz ; --sz) {
      std::string s(syllable.substr(0, sz));

      ConvertTable::const_iterator itr(convertTable.find(s));
      if (convertTable.end() != itr) {
         return Result(itr->first, itr->second);
      }
   }
   return Result();
}

/*!
 return matched result
 */
PhonemeTable::Result PhonemeTable::match(const std::string& syllable) const
{
   ConvertTable::const_iterator itr(convertTable.find(syllable));
   if (convertTable.end() != itr) {
      return Result(itr->first, itr->second);
   }
   return Result();
}

};  // namespace sinsy
