/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_MULTIBYTE_CHAR_RANGE_H_
#define SINSY_MULTIBYTE_CHAR_RANGE_H_

#include <string>
#include <vector>
#include "IConf.h"
#include "Configurations.h"
#include "PhonemeTable.h"
#include "MacronTable.h"

namespace sinsy
{

class MultibyteCharRange
{
public:
   //! constructor
   MultibyteCharRange();

   //! destructor
   virtual ~MultibyteCharRange();

   //! add multibyte char range
   bool addRange(size_t sz, unsigned char b, unsigned char e);

   //! get char size (if 1 or unknown, return 1)
   size_t getCharSize(unsigned char firstChar) const;

private:
   //! copy constructor (donot use)
   MultibyteCharRange(const MultibyteCharRange&);

   //! assignment operator (donot use)
   MultibyteCharRange& operator=(const MultibyteCharRange&);

   struct Range {
      //! default constructor
      Range() : size(0), begin(0), end(0) {}

      //! constructor
      Range(size_t s, unsigned char b, unsigned char e) : size(s), begin(b), end(e) {}

      //! size of multibyte char
      size_t size;

      //! begin code
      unsigned char begin;

      //! end code
      unsigned char end;
   };

   typedef std::vector<Range> RangeList;

   //! list of range
   RangeList rangeList;
};

};

#endif // SINSY_MULTIBYTE_CHAR_RANGE_H_
