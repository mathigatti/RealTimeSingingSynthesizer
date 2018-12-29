/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_PHONEME_LABELER_H_
#define SINSY_PHONEME_LABELER_H_

#include <vector>
#include <string>
#include "IPhonemeLabel.h"
#include "PhonemeInfo.h"

namespace sinsy
{

class PhonemeLabeler
{
public:
   static const std::string BREATH_PHONEME;

   //! constructor
   explicit PhonemeLabeler(const PhonemeInfo&);

   //! destructor
   virtual ~PhonemeLabeler();

   //! set label
   virtual void setLabel(IPhonemeLabel&, int overwriteEnableFlag = 0) const;

   //! get score flag
   ScoreFlag getScoreFlag() const;

   //! set index in syllable
   void setIdxInSyllable(size_t i);

   //! set number in syllable
   void setNumInSyllable(size_t n);

   //! get phoneme type
   const std::string& getPhonemeType() const;

   //! set count from previous vowel
   void setCountFromPrevVowel(size_t count);

   //! set count to next vowel
   void setCountToNextVowel(size_t count);

private:
   //! copy constructor (donot use)
   PhonemeLabeler(const PhonemeLabeler&);

   //! assignment operator (donot use)
   PhonemeLabeler& operator=(const PhonemeLabeler&);

   // phoneme information
   PhonemeInfo phonemeInfo;

   //! index in syllable
   size_t idxInSyllable;

   //! number in syllable
   size_t numInSyllable;

   //! count from prev vowel
   size_t countFromPrevVowel;

   //! count to next vowel
   size_t countToNextVowel;
};

};

#endif // SINSY_PHONEME_LABELER_H_
