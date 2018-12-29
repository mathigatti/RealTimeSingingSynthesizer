/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_J_CONF_H_
#define SINSY_J_CONF_H_

#include <string>
#include <set>
#include "IConf.h"
#include "Configurations.h"
#include "PhonemeTable.h"
#include "MacronTable.h"
#include "MultibyteCharRange.h"

namespace sinsy
{

class JConf : public IConf
{
public:
   //! constructor
   JConf(const std::string& enc);

   //! destructor
   virtual ~JConf();

   //! read phoneme table and config from files
   bool read(const std::string& table, const std::string& conf, const std::string& macron);

   //! convert lyrics to phonemes
   virtual bool convert(const std::string& enc, ConvertableList::iterator begin, ConvertableList::iterator end) const;

   //! get sil str
   virtual std::string getSilStr() const;

   //! check encoding
   bool checkEncoding(const std::string& enc) const;

   //! get multibyte char range
   const MultibyteCharRange& getMultibyteCharRange() const;

private:
   //! copy constructor (donot use)
   JConf(const JConf&);

   //! assignment operator (donot use)
   JConf& operator=(const JConf&);

   //! phoneme table
   PhonemeTable phonemeTable;

   //! configure
   Configurations config;

   //! macron table
   MacronTable macronTable;

   //! ranges of multibyte chars
   MultibyteCharRange multibyteCharRange;

   typedef std::set<std::string> Encodings;

   //! encoding
   Encodings encodings;
};

};

#endif // SINSY_J_CONF_H_
