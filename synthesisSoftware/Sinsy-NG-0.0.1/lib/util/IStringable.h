/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_I_STRINGABLE_H_
#define SINSY_I_STRINGABLE_H_

#include <iostream>

#include "util_types.h"

namespace sinsy
{

class IStringWritable
{
public:

   //! destructor
   virtual ~IStringWritable() {}

   //! to string stream
   virtual std::ostream& toStringStream(std::ostream&) const = 0;
};

//! to stream
std::ostream& operator<<(std::ostream&, const IStringWritable&);

};

#endif // SINSY_I_STRINGABLE_H_
