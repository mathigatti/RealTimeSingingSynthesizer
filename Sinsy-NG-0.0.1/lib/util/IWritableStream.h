/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_I_WRITE_STREAM_H_
#define SINSY_I_WRITE_STREAM_H_

#include "util_types.h"
#include "StreamException.h"

namespace sinsy
{

class IWritableStream
{
public:
   //! destructor
   virtual ~IWritableStream() {}

   /*!
    write data to stream
    @param buffer buffer for data that you want to write
    @param byte   byte you want to write
    @return       write bytes
   */
   virtual size_t write(const void* buffer, size_t byte) throw (StreamException) = 0;
};

/*!
 write data to stream
 */
template<class T>
IWritableStream& toStream(IWritableStream& stream, const T& value)
{
   size_t idx(0);
   const size_t size(sizeof(value));
   while (idx < size) {
      size_t result(stream.write(reinterpret_cast<const char*>(&value) + idx, size - idx));
      if (result <= 0) {
         throw StreamException("cannot write to IWritableStream");
      }
      idx += result;
   }
   return stream;
}

/*!
 write data to stream (char)
 */
inline IWritableStream& operator<<(IWritableStream& stream, char buf) throw (StreamException)
{
   return toStream(stream, buf);
}

/*!
 write data to stream (unsigned char)
 */
inline IWritableStream& operator<<(IWritableStream& stream, unsigned char buf) throw (StreamException)
{
   return toStream(stream, buf);
}

/*!
 write data to stream (INT16)
 */
inline IWritableStream& operator<<(IWritableStream& stream, INT16 buf) throw (StreamException)
{
   return toStream(stream, buf);
}

/*!
 write data to stream (UINT16)
 */
inline IWritableStream& operator<<(IWritableStream& stream, UINT16 buf) throw (StreamException)
{
   return toStream(stream, buf);
}

/*!
 write data to stream (INT32)
 */
inline IWritableStream& operator<<(IWritableStream& stream, INT32 buf) throw (StreamException)
{
   return toStream(stream, buf);
}

/*!
 write data to stream (UINT32)
 */
inline IWritableStream& operator<<(IWritableStream& stream, UINT32 buf) throw (StreamException)
{
   return toStream(stream, buf);
}

/*!
 write data to stream (INT64)
 */
inline IWritableStream& operator<<(IWritableStream& stream, INT64 buf) throw (StreamException)
{
   return toStream(stream, buf);
}

/*!
 write data to stream (UINT64)
 */
inline IWritableStream& operator<<(IWritableStream& stream, UINT64 buf) throw (StreamException)
{
   return toStream(stream, buf);
}

/*!
 write data to stream (float)
 */
inline IWritableStream& operator<<(IWritableStream& stream, float buf) throw (StreamException)
{
   return toStream(stream, buf);
}

/*!
 write data to stream (double)
 */
inline IWritableStream& operator<<(IWritableStream& stream, double buf) throw (StreamException)
{
   return toStream(stream, buf);
}

/*!
 write data to stream (long double)
 */
inline IWritableStream& operator<<(IWritableStream& stream, long double buf) throw (StreamException)
{
   return toStream(stream, buf);
}

};

#endif // SINSY_I_WRITE_STREAM_H_
