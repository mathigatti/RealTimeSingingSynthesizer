/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_STREAM_EXCEPTION_H_
#define SINSY_STREAM_EXCEPTION_H_

#include <exception>
#include <string>
#include <stdexcept>
#include "util_types.h"

namespace sinsy
{

class StreamException : public std::runtime_error
{
public:
   //! constructor
   explicit StreamException(const std::string& msg) : runtime_error(msg) {}

   //! destructor
   virtual ~StreamException() throw() {}
};

};

#endif // SINSY_STREAM_EXCEPTION_H_
