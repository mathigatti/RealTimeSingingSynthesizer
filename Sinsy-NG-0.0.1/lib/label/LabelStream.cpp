/* Created by Ghost Gloomy on 2018/11/8. */

#include "util_log.h"
#include "LabelStream.h"

namespace sinsy
{

/*!
 constructor
 */
LabelStream::LabelStream(std::ostream& os) : stream(os)
{
}

/*!
 destructor
 */
LabelStream::~LabelStream()
{
}

/*!
 output label

 @param str label string
 */
void LabelStream::output(const std::string& str)
{
   stream << str << std::endl;
}

};  // namespace sinsy
