/* Created by Ghost Gloomy on 2018/11/8. */
#ifndef SINSY_SYLLABLE_LABELER_H_
#define SINSY_SYLLABLE_LABELER_H_

#include <vector>
#include "LabelPosition.h"
#include "PhonemeLabeler.h"
#include "ISyllableLabel.h"

namespace sinsy
{

class SyllableLabeler
{
public:
   typedef std::vector<PhonemeLabeler*> List;

   //! constructor
   explicit SyllableLabeler(const std::string& lang);

   //! destructor
   virtual ~SyllableLabeler();

   //! set label
   virtual void setLabel(ISyllableLabel&) const;

   //! add phoneme
   void addChild(PhonemeLabeler* l);

   //! get begin iterator of phonemes
   List::const_iterator childBegin() const;

   //! get end interator of phonemes
   List::const_iterator childEnd() const;

   //! set language dependent information
   void setInfo(const std::string& str);

   //! set index in note
   void setIdxInNote(size_t i);

   //! set number in note
   void setNumInNote(size_t n);

   //! set phoneme positions
   void setPhonemePositions();

private:
   //! copy constructor (donot use)
   SyllableLabeler(const SyllableLabeler&);

   //! assignment operator (donot use)
   SyllableLabeler& operator=(const SyllableLabeler&);

   //! children (phonemes)
   List children;

   //! language
   std::string language;

   //! index in note
   size_t idxInNote;

   //! number in note
   size_t numInNote;

   //! language dependent information
   std::string langDependentInfo;
};

};

#endif // SINSY_SYLLABLE_LABELER_H_
