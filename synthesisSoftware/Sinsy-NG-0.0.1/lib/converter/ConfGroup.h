/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_CONF_GROUP_H_
#define SINSY_CONF_GROUP_H_

#include <vector>
#include "IConf.h"

namespace sinsy
{

class ConfGroup : public IConf
{
public:
   //! constructor
   ConfGroup();

   //! destructor
   virtual ~ConfGroup();

   //! add conf
   void add(const IConf* conf);

   //! convert lyrics to phonemes
   virtual bool convert(const std::string& enc, ConvertableList::iterator begin, ConvertableList::iterator end) const;

   //! clear all confs
   void clear();

   //! get sil string
   virtual std::string getSilStr() const;

private:
   //! copy constructor (donot use)
   ConfGroup(const ConfGroup&);

   //! assignment operator (donot use)
   ConfGroup& operator=(const ConfGroup&);

   //! config list type
   typedef std::vector<const IConf*> ConfList;

   //! conf list
   ConfList confs;
};

};

#endif // SINSY_CONF_GROUP_H_
