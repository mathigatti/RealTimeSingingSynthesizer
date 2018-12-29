/* Created by Ghost Gloomy on 2018/11/8. */

#include "IStringable.h"

namespace sinsy
{

/*!
 to stream
 */
std::ostream& operator<<(std::ostream& os, const IStringWritable& obj)
{
   return obj.toStringStream(os);
}

};  // namespace sinsy
