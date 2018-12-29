/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_STRING_TOKENIZER_H_
#define SINSY_STRING_TOKENIZER_H_

#include "util_types.h"
#include <string>
#include <vector>

namespace sinsy
{

class StringTokenizer
{
public:
   //! constructor
   StringTokenizer(const ::std::string& str, const std::string& separator);

   //! destructor
   virtual ~StringTokenizer();

   //! access at element of idx
   std::string at(size_t idx) const;

   //! get size
   size_t size() const;

private:
   //! copy constructor (donot use)
   StringTokenizer(const StringTokenizer&);

   //! assignment operator (donot use)
   StringTokenizer& operator=(const StringTokenizer&);

   typedef std::vector<std::string> Values;

   //! value
   Values values;
};

};

#endif // SINSY_STRING_TOKENIZER_H_
