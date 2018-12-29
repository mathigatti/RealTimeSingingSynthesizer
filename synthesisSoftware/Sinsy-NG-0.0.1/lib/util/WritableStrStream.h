/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_WRITABLE_STR_STREAM_H_
#define SINSY_WRITABLE_STR_STREAM_H_

#include <sstream>
#include <iostream>
#include "util_types.h"
#include "StreamException.h"
#include "IWritableStream.h"

namespace sinsy
{

class WritableStrStream
{
public:
   //! constructor
   explicit WritableStrStream(IWritableStream& s) : stream(s) {}

   //! destructor
   virtual ~WritableStrStream() {}

   /*!
    convert data to string and write to stream
    */
   template<class T>
   WritableStrStream& operator<<(const T& buf) throw (StreamException) {
      oss << buf;
      stream.write((const void*)oss.str().c_str(), oss.str().length());
      oss.str("");
      return *this;
   }

private:
   //! copy constructor (donot use)
   WritableStrStream(const WritableStrStream&);

   //! assignment operator (donot use)
   WritableStrStream& operator=(const WritableStrStream&);

   //! stream
   IWritableStream& stream;

   //! stringstream for conversion to string
   std::ostringstream oss;
};

};

#endif // SINSY_WRITABLE_STR_STREAM_H_
