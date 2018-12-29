/* Created by Ghost Gloomy on 2018/11/8. */

#include <fstream>
#include "Configurations.h"
#include "util_log.h"
#include "util_string.h"
#include "StringTokenizer.h"

namespace sinsy
{

namespace
{
const std::string SEPARATOR = "=";
};

/*!
 constructor
 */
Configurations::Configurations()
{
}

/*!
 destructor
 */
Configurations::~Configurations()
{
   clear();
}

/*!
 clear
 */
void Configurations::clear()
{
   configs.clear();
}

/*!
 read configurations from file
 */
bool Configurations::read(const std::string& fpath)
{
   std::ifstream ifs(fpath.c_str());
   if (!ifs) {
      ERR_MSG("Cannot open config file : " << fpath);
      return false;
   }

   clear();

   std::string buffer;

   while (!ifs.eof()) {
      std::getline(ifs, buffer);

      // remove comments
      size_t idx = buffer.find("#");
      if (idx != std::string::npos) {
         buffer.resize(idx);
      }
      StringTokenizer st(buffer, SEPARATOR);

      size_t sz(st.size());
      if (0 == sz) {
         continue;
      } else if (2 != st.size()) {
         ERR_MSG("Syntax error : " << fpath);
         return false;
      }

      std::string key(st.at(0));
      cutBlanks(key);
      std::string value(st.at(1));
      cutBlanks(value);
      if (key.empty() || value.empty()) {
         ERR_MSG("Syntax error : " << fpath);
         return false;
      }

      // cut " and '
      if (1 < value.size()) {
         if ((('\"' == value[0]) && ('\"' == value[value.size() - 1])) || (('\'' == value[0]) && ('\'' == value[value.size() - 1]))) {
            value = value.substr(1, value.size() - 2);
            cutBlanks(value);
            if (value.empty()) {
               ERR_MSG("Syntax error : " << fpath);
               return false;
            }
         }
      }
      configs.insert(std::make_pair/*<std::string, std::string>*/(key, value));
   }
   return true;
}

/*!
 for std::string (need default)
 */
template<>
std::string Configurations::get<std::string>(const std::string& key, const std::string& def) const
{
   Configs::const_iterator itr(configs.find(key));
   if (configs.end() != itr) {
      return itr->second;
   }
   return def;
}

/*!
 for std::string (not need default)
 */
std::string Configurations::get(const std::string& key) const
{
   Configs::const_iterator itr(configs.find(key));
   if (configs.end() != itr) {
      return itr->second;
   }
   return std::string();
}

/*!
 for bool
 */
template<>
bool Configurations::get<bool>(const std::string& key, const bool& def) const
{
   Configs::const_iterator itr(configs.find(key));
   if (configs.end() != itr) {
      std::string value(itr->second);
      toLower(value);

      if (value == "true") {
         return true;
      } else if (value == "false") {
         return false;
      }

      int i(-1);
      std::istringstream iss(value);
      iss >> i;
      if (0 == i) {
         return false;
      } else if (0 < i) {
         return true;
      }
   }
   return def;
}

};  // namespace sinsy
