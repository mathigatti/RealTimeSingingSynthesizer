/* Created by Ghost Gloomy on 2018/11/8. */

#include "PhonemeLabeler.h"
#include "util_log.h"
#include <stdexcept>

namespace sinsy
{

const std::string PhonemeLabeler::BREATH_PHONEME = "br"; //!< breath

/*!
 constructor
 */
PhonemeLabeler::PhonemeLabeler(const PhonemeInfo& p) : phonemeInfo(p), idxInSyllable(0), numInSyllable(0), countFromPrevVowel(0), countToNextVowel(0)
{
}

/*!
 destructor
 */
PhonemeLabeler::~PhonemeLabeler()
{
}

/*!
 set label
 */
void PhonemeLabeler::setLabel(IPhonemeLabel& label, int overwriteEnableFlag) const
{
   label.setType(phonemeInfo.getType());
   label.setName(phonemeInfo.getPhoneme());

   ScoreFlag flag(phonemeInfo.getScoreFlag());

   if (1 == overwriteEnableFlag) {
      unsetDisableFlag(flag);
   } else if (2 == overwriteEnableFlag) {
      setDisableFlag(flag);
   } else if (0 != overwriteEnableFlag) {
      throw std::invalid_argument("PhonemeLabeler::setLabel() Overwrite enable flag is invalid");
   }

   label.setFlag(getScoreFlagStr(flag));

   if (numInSyllable < idxInSyllable) {
      throw std::runtime_error("PhonemeLabeler::setLabel() numInSyllable < idxInSyllable");
   }
   label.setPositionInSyllable(idxInSyllable, numInSyllable);

   label.setCountFromPrevVowel(countFromPrevVowel);
   label.setCountToNextVowel(countToNextVowel);
}

/*!
 get score flag
 */
ScoreFlag PhonemeLabeler::getScoreFlag() const
{
   return phonemeInfo.getScoreFlag();
}

/*!
 set index in syllable
 */
void PhonemeLabeler::setIdxInSyllable(size_t i)
{
   idxInSyllable = i;
}

/*!
 set number in syllable
 */
void PhonemeLabeler::setNumInSyllable(size_t n)
{
   numInSyllable = n;
}

/*!
 get phoneme type
 */
const std::string& PhonemeLabeler::getPhonemeType() const
{
   return phonemeInfo.getType();
}

/*!
 set count from previous vowel
 */
void PhonemeLabeler::setCountFromPrevVowel(size_t count)
{
   this->countFromPrevVowel = count;
}

/*!
 set count to next vowel
 */
void PhonemeLabeler::setCountToNextVowel(size_t count)
{
   this->countToNextVowel = count;
}

};  // namespace sinsy
