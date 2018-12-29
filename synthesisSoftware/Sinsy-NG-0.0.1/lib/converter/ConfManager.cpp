/* Created by Ghost Gloomy on 2018/11/8. */

#include <stdexcept>
#include <algorithm>
#include "util_log.h"
#include "StringTokenizer.h"
#include "Deleter.h"
#include "ConfManager.h"
#include "ConfGroup.h"
#include "util_converter.h"
#include "JConf.h"

namespace sinsy
{

namespace
{
const std::string UTF_8_STRS("utf_8, utf8, utf-8");
const std::string SHIFT_JIS_STRS("shift_jis, shift-jis, sjis");
const std::string EUC_JP_STRS("euc-jp, euc_jp, eucjp");
const std::string CODE_SEPARATOR = "|";
};

/*!
 constructor
 */
ConfManager::ConfManager() : uJConf(NULL), sJConf(NULL), eJConf(NULL), jConfs(NULL)
{
}

/*!
 destructor
*/
ConfManager::~ConfManager()
{
   clear();
}

/*!
 @internal

 clear all confs
*/
void ConfManager::clear()
{
   std::for_each(deleteList.begin(), deleteList.end(), Deleter<IConf>());
   deleteList.clear();
   uJConf = NULL;
   sJConf = NULL;
   eJConf = NULL;
   jConfs = NULL;
   confList.clear();
}

/*!
 @internal

 add Japanese conf
 */
void ConfManager::addJConf(IConf* conf)
{
   if (!jConfs) {
      jConfs = new ConfGroup();
      deleteList.push_back(jConfs);
      confList.push_back(jConfs);
   }
   jConfs->add(conf);
}

/*!
 set languages
 (Currently, you can set only Japanese (j))
 */
bool ConfManager::setLanguages(const std::string& languages, const std::string& dirPath)
{
   clear();

   const std::string::const_iterator itrEnd(languages.end());
   for (std::string::const_iterator itr(languages.begin()); itrEnd != itr; ++itr) {
      char lang(*itr);
      switch (lang) {
      case 'j' : { // Japanese
         const std::string TABLE_UTF_8(dirPath + "/japanese.utf_8.table");
         const std::string CONF_UTF_8(dirPath + "/japanese.utf_8.conf");
         const std::string TABLE_SHIFT_JIS(dirPath + "/japanese.shift_jis.table");
         const std::string CONF_SHIFT_JIS(dirPath + "/japanese.shift_jis.conf");
         const std::string TABLE_EUC_JP(dirPath + "/japanese.euc_jp.table");
         const std::string CONF_EUC_JP(dirPath + "/japanese.euc_jp.conf");
         const std::string MACRON_TABLE(dirPath + "/japanese.macron");

         uJConf = new JConf(UTF_8_STRS);
         sJConf = new JConf(SHIFT_JIS_STRS);
         eJConf = new JConf(EUC_JP_STRS);

         // utf-8
         if (!uJConf->read(TABLE_UTF_8, CONF_UTF_8, MACRON_TABLE)) {
            ERR_MSG("Cannot read Japanese table or config or macron file : " << TABLE_UTF_8 << ", " << CONF_UTF_8);
            delete uJConf;
            uJConf = NULL;
            return false;
         }
         addJConf(uJConf);
         deleteList.push_back(uJConf);


         // shift_jis
         if (!sJConf->read(TABLE_SHIFT_JIS, CONF_SHIFT_JIS, MACRON_TABLE)) {
            ERR_MSG("Cannot read Japanese table or config or macron file :" << TABLE_SHIFT_JIS << ", " << CONF_SHIFT_JIS);
            delete sJConf;
            sJConf = NULL;
            return false;
         }
         addJConf(sJConf);
         deleteList.push_back(sJConf);

         // euc-jp
         if (!eJConf->read(TABLE_EUC_JP, CONF_EUC_JP, MACRON_TABLE)) {
            ERR_MSG("Cannot read Japanese table or config or macron file : " << TABLE_EUC_JP << ", " << CONF_EUC_JP);
            delete eJConf;
            eJConf = NULL;
            return false;
         }
         addJConf(eJConf);
         deleteList.push_back(eJConf);

         break;
      }
      default :
         ERR_MSG("Unknown language flag : " << lang);
         return false;
      }
   }
   return true;
}

/*!
 set default confs
 */
void ConfManager::setDefaultConfs(ConfGroup& confs) const
{
   confs.clear();
   const ConfList::const_iterator itrEnd(confList.end());
   for (ConfList::const_iterator itr(confList.begin()); itrEnd != itr ; ++itr) {
      confs.add(*itr);
   }
   // unknown conf
   confs.add(&uConf);

   return;
}

};  // namespace sinsy
