/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_CONF_MANAGER_H_
#define SINSY_CONF_MANAGER_H_

#include "IConf.h"
#include "ConfGroup.h"
#include "UnknownConf.h"

namespace sinsy
{
class Converter;
class JConf;

class ConfManager
{
public:
   //! constructor
   ConfManager();

   //! destructor
   virtual ~ConfManager();

   //! set confs to converter
   bool setLanguages(const std::string& languages, const std::string& dirPath);

   //! set default confs
   void setDefaultConfs(ConfGroup& confs) const;

private:
   //! copy constructor (donot use)
   ConfManager(const ConfManager&);

   //! assignment operator (donot use)
   ConfManager& operator=(const ConfManager&);

   //! clear all confs
   void clear();

   //! add Japanese conf
   void addJConf(IConf* conf);

   //! Japanese conf (UTF-8)
   JConf* uJConf;

   //! Japanese conf (Shift_JIS)
   JConf* sJConf;

   //! Japanese conf (EUC-JP)
   JConf* eJConf;

   //! japanese confs
   ConfGroup* jConfs;

   //! conf for unknown language
   const UnknownConf uConf;

   typedef std::vector<IConf*> ConfList;

   //! list of IConf
   ConfList confList;

   //!< list of IConf to delete
   ConfList deleteList;
};

};

#endif // SINSY_CONF_MANAGER_H_
