/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_I_CONVERTABLE_H_
#define SINSY_I_CONVERTABLE_H_

#include <vector>
#include <string>
#include "util_log.h"
#include "Syllabic.h"
#include "util_converter.h"
#include "PhonemeInfo.h"

namespace sinsy
{

class IConvertable
{
public:
   //! destructor
   virtual ~IConvertable() {}

   //! If this is a rest, return true.
   virtual bool isRest() const = 0;

   //! If this is already converted, return true.
   virtual bool isConverted() const = 0;

   //! get lyric
   virtual std::string getLyric() const = 0;

   //! get syllabic
   virtual Syllabic getSyllabic() const = 0;

   //! add info (lyric, phonemes, and so on...)
   virtual void addInfo(const std::vector<PhonemeInfo>& phonemes, const std::string& language = "", const std::string& info = "") = 0;
};

};

#endif // SINSY_I_CONVERTABLE_H_
