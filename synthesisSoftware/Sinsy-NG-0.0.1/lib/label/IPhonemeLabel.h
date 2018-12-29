/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_I_PHONEME_LABEL_H_
#define SINSY_I_PHONEME_LABEL_H_

namespace sinsy
{

class IPhonemeLabel
{
public:
   //! destructor
   virtual ~IPhonemeLabel() {}

   //! set type
   virtual void setType(const std::string& value) = 0;

   //! set name
   virtual void setName(const std::string& name) = 0;

   //! set flag
   virtual void setFlag(const std::string& flag) = 0;

   //! set position in syllable
   virtual void setPositionInSyllable(size_t idx, size_t max) = 0;

   //! set count from previous vowel
   virtual void setCountFromPrevVowel(size_t count) = 0;

   //! set count to next vowel
   virtual void setCountToNextVowel(size_t count) = 0;
};

};

#endif // SINSY_I_PHONEME_LABEL_H_
