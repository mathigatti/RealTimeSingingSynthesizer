/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_I_CONF_H_
#define SINSY_I_CONF_H_

#include <vector>
#include "IConvertable.h"

namespace sinsy
{

class IConf
{
public:
   //! destructor
   virtual ~IConf() {}

   typedef std::vector<IConvertable*> ConvertableList;

   //! convert
   virtual bool convert(const std::string& enc, ConvertableList::iterator begin, ConvertableList::iterator end) const = 0;

   //! get sil string
   virtual std::string getSilStr() const = 0;
};

};

#endif // SINSY_I_CONF_H_
