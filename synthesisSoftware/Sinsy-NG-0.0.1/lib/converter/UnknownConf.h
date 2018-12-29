/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_UNKNOWN_CONF_H_
#define SINSY_UNKNOWN_CONF_H_

#include <vector>
#include "IConf.h"

namespace sinsy
{

class UnknownConf : public IConf
{
public:
   //! constructor
   UnknownConf();

   //! destructor
   virtual ~UnknownConf();

   //! convert lyrics to phonemes
   virtual bool convert(const std::string& enc, ConvertableList::iterator begin, ConvertableList::iterator end) const;

   void clear();

   //! get sil str
   virtual std::string getSilStr() const;

private:
   //! copy constructor (donot use)
   UnknownConf(const UnknownConf&);

   //! assignment operator (donot use)
   UnknownConf& operator=(const UnknownConf&);
};

};

#endif // SINSY_UNKNOWN_CONF_H_
