/* Created by Ghost Gloomy on 2018/11/8. */

#include "util_log.h"
#include "PhonemeInfo.h"

namespace sinsy
{

const std::string PhonemeInfo::TYPE_SILENT    = "s";
const std::string PhonemeInfo::TYPE_PAUSE     = "p";
const std::string PhonemeInfo::TYPE_VOWEL     = "v";
const std::string PhonemeInfo::TYPE_CONSONANT = "c";
const std::string PhonemeInfo::TYPE_BREAK     = "b";

/*!
 constructor
 */
PhonemeInfo::PhonemeInfo() : scoreFlag(0)
{
}

/*!
 constructor
 */
PhonemeInfo::PhonemeInfo(const std::string& t, const std::string& p, ScoreFlag f) : type(t), phoneme(p), scoreFlag(f)
{
}

/*!
 copy constructor
 */
PhonemeInfo::PhonemeInfo(const PhonemeInfo& obj) : type(obj.type), phoneme(obj.phoneme), scoreFlag(obj.scoreFlag)
{
}

/*!
 destructor
 */
PhonemeInfo::~PhonemeInfo()
{
}

/*!
 assignment operator
 */
PhonemeInfo& PhonemeInfo::operator=(const PhonemeInfo& obj)
{
   this->type = obj.type;
   this->phoneme = obj.phoneme;
   this->scoreFlag = obj.scoreFlag;
   return *this;
}

/*!
 get type
 */
const std::string& PhonemeInfo::getType() const
{
   return this->type;
}

/*!
 get phoneme
 */
const std::string& PhonemeInfo::getPhoneme() const
{
   return this->phoneme;
}

/*!
 set phoneme
 */
void PhonemeInfo::setPhoneme(const std::string& p)
{
   this->phoneme = p;
}

/*!
 return score flag
 */
ScoreFlag PhonemeInfo::getScoreFlag() const
{
   return this->scoreFlag;
}

};  // namespace sinsy
