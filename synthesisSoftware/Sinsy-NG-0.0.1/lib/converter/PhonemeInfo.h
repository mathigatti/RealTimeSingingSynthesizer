/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_PHONEME_INFO_H_
#define SINSY_PHONEME_INFO_H_

#include <string>
#include "util_converter.h"

namespace sinsy
{

class PhonemeInfo
{
public:
   static const std::string TYPE_SILENT;
   static const std::string TYPE_PAUSE;
   static const std::string TYPE_VOWEL;
   static const std::string TYPE_CONSONANT;
   static const std::string TYPE_BREAK;

   //! constructor
   PhonemeInfo();

   //! constructor
   PhonemeInfo(const std::string& type, const std::string& phoneme, ScoreFlag flag = 0);

   //! copy constructor
   PhonemeInfo(const PhonemeInfo& obj);

   //! destructor
   virtual ~PhonemeInfo();

   //! assignment operator
   PhonemeInfo& operator=(const PhonemeInfo&);

   //! get type
   const std::string& getType() const;

   //! get phoneme
   const std::string& getPhoneme() const;

   //! set phoneme
   void setPhoneme(const std::string& p);

   ScoreFlag getScoreFlag() const;

private:
   //! type (TYPE_SILENT, TYPE_PAUSE, ..., or TYPE_BREAK)
   std::string type;

   //! phoneme
   std::string phoneme;

   ScoreFlag scoreFlag;
};

};

#endif // SINSY_PHONEME_INFO_H_
