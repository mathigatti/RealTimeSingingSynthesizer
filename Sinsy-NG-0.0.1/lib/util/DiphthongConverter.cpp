/* Created by Ghost Gloomy on 2018/11/8. */

#include <fstream>
#include "DiphthongConverter.h"
#include "util_log.h"

namespace sinsy
{

/*!
 constructor
 */
DiphthongConverter::DiphthongConverter()
{
}

/*!
 destructor
 */
DiphthongConverter::~DiphthongConverter()
{
}

/*!
 clear
 */
void DiphthongConverter::clear()
{
   convMap.clear();
}

/*!
 insert diphthong conversion rule
 */
bool DiphthongConverter::insert(const std::string& diphthong, const std::string& front, const std::string& back)
{
   return convMap.insert(std::make_pair(diphthong, std::make_pair(front, back))).second;
}

/*!
 get front of converted phonemes
 */
std::string DiphthongConverter::getFront(const std::string& diphthong) const
{
   ConvMap::const_iterator itr(convMap.find(diphthong));
   if (convMap.end() == itr) {
      return diphthong;
   }
   return itr->second.first;
}

/*!
 get back of converted phonemes
 */
std::string DiphthongConverter::getBack(const std::string& diphthong) const
{
   ConvMap::const_iterator itr(convMap.find(diphthong));
   if (convMap.end() == itr) {
      return diphthong;
   }
   return itr->second.second;
}

};  // namespace sinsy
