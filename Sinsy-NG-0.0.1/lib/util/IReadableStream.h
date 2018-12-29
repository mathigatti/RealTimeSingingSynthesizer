/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_I_READ_STREAM_H_
#define SINSY_I_READ_STREAM_H_

#include "util_types.h"
#include "StreamException.h"

namespace sinsy
{

class IReadableStream
{
public:
   //! destructor
   virtual ~IReadableStream() {}

   /*!
    read data from stream

    @param buffer buffer for read data
    @param byte   byte you want to read
    @return       read bytes (0 : end of stream)
   */
   virtual size_t read(void* buffer, size_t byte) throw (StreamException) = 0;
};

/*!
 read data from stream
 */
template<class T>
IReadableStream& fromStream(IReadableStream& stream, T& buf) throw (StreamException)
{
   size_t idx(0);
   const size_t sz(sizeof(buf));
   while (idx < sz) {
      size_t result(stream.read(reinterpret_cast<char*>(&buf) + idx, sz - idx));
      if (result <= 0) {
         throw StreamException("cannot read from IReadableStream");
      }
      idx += result;
   }
   return stream;
}

/*!
 read data from stream (char)
 */
inline IReadableStream& operator>>(IReadableStream& stream, char& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

/*!
 read data from stream (unsigned char)
 */
inline IReadableStream& operator>>(IReadableStream& stream, unsigned char& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

/*!
 read data from stream (INT16)
 */
inline IReadableStream& operator>>(IReadableStream& stream, INT16& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

/*!
 read data from stream (UINT16)
 */
inline IReadableStream& operator>>(IReadableStream& stream, UINT16& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

/*!
 read data from stream (INT32)
 */
inline IReadableStream& operator>>(IReadableStream& stream, INT32& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

/*!
 read data from stream (UINT32)
 */
inline IReadableStream& operator>>(IReadableStream& stream, UINT32& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

/*!
 read data from stream (INT64)
 */
inline IReadableStream& operator>>(IReadableStream& stream, INT64& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

/*!
 read data from stream (UINT64)
 */
inline IReadableStream& operator>>(IReadableStream& stream, UINT64& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

/*!
 read data from stream (float)
 */
inline IReadableStream& operator>>(IReadableStream& stream, float& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

/*!
 read data from stream (double)
 */
inline IReadableStream& operator>>(IReadableStream& stream, double& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

/*!
 read data from stream (long double)
 */
inline IReadableStream& operator>>(IReadableStream& stream, long double& buf) throw (StreamException)
{
   return fromStream(stream, buf);
}

};

#endif // SINSY_I_READ_STREAM_H_
