/* Created by Ghost Gloomy on 2018/11/8. */
#ifndef SINSY_I_SYLLABLE_LABEL_H_
#define SINSY_I_SYLLABLE_LABEL_H_

#include <vector>
#include "LabelPosition.h"
#include "PhonemeLabeler.h"

namespace sinsy
{

class ISyllableLabel
{
public:
   //! destructor
   virtual ~ISyllableLabel() {}

   //! set number of phonemes
   virtual void setPhonemeNum(size_t num) = 0;

   //! set position in note
   virtual void setPositionInNote(size_t idx, size_t max) = 0;

   //! set language
   virtual void setLanguage(const std::string& language) = 0;

   //! set language-dependent infomation
   virtual void setLangDependentInfo(const std::string& info) = 0;
};

};

#endif // SINSY_I_SYLLABLE_LABEL_H_
