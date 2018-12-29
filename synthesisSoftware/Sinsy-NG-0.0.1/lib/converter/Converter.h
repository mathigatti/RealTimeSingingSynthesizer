/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_CONVERTER_H_
#define SINSY_CONVERTER_H_

#include <vector>
#include "IConf.h"
#include "ConfManager.h"

namespace sinsy
{

class Converter
{
public:
   //! constructor
   Converter();

   //! destructor
   virtual ~Converter();

   //! clear
   void clear();

   //! set confs to converter
   bool setLanguages(const std::string& languages, const std::string& dirPath);

   //! get sil str
   std::string getSilStr() const;

   //! convert
   virtual bool convert(const std::string& enc, IConf::ConvertableList::iterator begin, IConf::ConvertableList::iterator end) const;

private:
   //! copy constructor (donot use)
   Converter(const Converter&);

   //! assignment operator (donot use)
   Converter& operator=(const Converter&);

   //! config manager
   ConfManager confManager;

   //! config list type
   typedef std::vector<IConf*> ConfList;

   //! config list
   ConfList confs;
};

};

#endif // SINSY_CONVERTER_H_
