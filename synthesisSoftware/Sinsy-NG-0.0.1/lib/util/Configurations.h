/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_CONFIGURATIONS_H_
#define SINSY_CONFIGURATIONS_H_

#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include "util_types.h"

namespace sinsy
{

class Configurations
{
public:
   //! constructor
   Configurations();

   //! destructor
   virtual ~Configurations();

   //! clear
   void clear();

   //! read configurations from file
   bool read(const std::string& fpath);

   //! get
   template<class T> T get(const std::string&, const T&) const;

   //! get
   std::string get(const std::string&) const;

private:
   //! copy constructor (donot use)
   Configurations(const Configurations&);

   //! assignment operator (donot use)
   Configurations& operator=(const Configurations&);

   typedef std::map<std::string, std::string> Configs;

   //! configs
   Configs configs;
};

/*!
 get

 @param key
 @param def default value
 @return
 */
template<class T>
T Configurations::get(const std::string& key, const T& def) const
{
   T ret(def);
   Configs::const_iterator itr(configs.find(key));
   if (configs.end() != itr) {
      std::istringstream iss(itr->second);
      iss >> ret;
   }
   return ret;
}

/*!
 get (std::string)
 */
template<>
std::string Configurations::get<std::string>(const std::string& key, const std::string& def) const;

/*!
 get (bool)
 */
template<>
bool Configurations::get<bool>(const std::string& key, const bool& def) const;

};

#endif // SINSY_CONFIGURATIONS_H_
