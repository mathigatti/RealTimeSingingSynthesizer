/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_UTIL_TYPES_H_
#define SINSY_UTIL_TYPES_H_

namespace sinsy
{

#ifndef INT8
#ifdef _WIN32
typedef __int8 INT8;
#elif (SIZEOF_CHAR==1)
typedef char INT8;
#elif (SIZEOF_SHORT==1)
typedef short INT8;
#elif (SIZEOF_INT==1)
typedef int INT8;
#elif (SIZEOF_LONG==1)
typedef long INT8;
#elif (SIZEOF_LONG_LONG==1)
typedef long long INT8;
#else
typedef char INT8;
#endif
#endif

#ifndef UINT8
#ifdef _WIN32
typedef unsigned __int8 UINT8;
#elif (SIZEOF_UNSIGNED_CHAR==1)
typedef unsigned char UINT8;
#elif (SIZEOF_UNSIGNED_SHORT==1)
typedef unsigned short UINT8;
#elif (SIZEOF_UNSIGNED_INT==1)
typedef unsigned int UINT8;
#elif (SIZEOF_UNSIGNED_LONG==1)
typedef unsigned long UINT8;
#elif (SIZEOF_UNSIGNED_LONG_LONG==1)
typedef unsigned long long UINT8;
#else
typedef unsigned char UINT8;
#endif
#endif

#ifndef INT16
#ifdef _WIN32
typedef __int16 INT16;
#elif (SIZEOF_CHAR==2)
typedef char INT16;
#elif (SIZEOF_SHORT==2)
typedef short INT16;
#elif (SIZEOF_INT==2)
typedef int INT16;
#elif (SIZEOF_LONG==2)
typedef long INT16;
#elif (SIZEOF_LONG_LONG==2)
typedef long long INT16;
#else
typedef short INT16;
#endif
#endif

#ifndef UINT16
#ifdef _WIN32
typedef unsigned __int16 UINT16;
#elif (SIZEOF_UNSIGNED_CHAR==2)
typedef unsigned char UINT16;
#elif (SIZEOF_UNSIGNED_SHORT==2)
typedef unsigned short UINT16;
#elif (SIZEOF_UNSIGNED_INT==2)
typedef unsigned int UINT16;
#elif (SIZEOF_UNSIGNED_LONG==2)
typedef unsigned long UINT16;
#elif (SIZEOF_UNSIGNED_LONG_LONG==2)
typedef unsigned long long UINT16;
#else
typedef unsigned short UINT16;
#endif
#endif

#ifndef INT32
#ifdef _WIN32
typedef __int32 INT32;
#elif (SIZEOF_CHAR==4)
typedef char INT32;
#elif (SIZEOF_SHORT==4)
typedef short INT32;
#elif (SIZEOF_INT==4)
typedef int INT32;
#elif (SIZEOF_LONG==4)
typedef long INT32;
#elif (SIZEOF_LONG_LONG==4)
typedef long long INT32;
#else
typedef int INT32;
#endif
#endif

#ifndef UINT32
#ifdef _WIN32
typedef unsigned __int32 UINT32;
#elif (SIZEOF_UNSIGNED_CHAR==4)
typedef unsigned char UINT32;
#elif (SIZEOF_UNSIGNED_SHORT==4)
typedef unsigned short UINT32;
#elif (SIZEOF_UNSIGNED_INT==4)
typedef unsigned int UINT32;
#elif (SIZEOF_UNSIGNED_LONG==4)
typedef unsigned long UINT32;
#elif (SIZEOF_UNSIGNED_LONG_LONG==4)
typedef unsigned long long UINT32;
#else
typedef unsigned int UINT32;
#endif
#endif

#ifndef INT64
#ifdef _WIN32
typedef __int64 INT64;
#elif (SIZEOF_CHAR==8)
typedef char INT64;
#elif (SIZEOF_SHORT==8)
typedef short INT64;
#elif (SIZEOF_INT==8)
typedef int INT64;
#elif (SIZEOF_LONG==8)
typedef long INT64;
#elif (SIZEOF_LONG_LONG==8)
typedef long long INT64;
#else
typedef long long INT64;
#endif
#endif

#ifndef UINT64
#ifdef _WIN32
typedef unsigned __int64 UINT64;
#elif (SIZEOF_UNSIGNED_CHAR==8)
typedef unsigned char UINT64;
#elif (SIZEOF_UNSIGNED_SHORT==8)
typedef unsigned short UINT64;
#elif (SIZEOF_UNSIGNED_INT==8)
typedef unsigned int UINT64;
#elif (SIZEOF_UNSIGNED_LONG==8)
typedef unsigned long UINT64;
#elif (SIZEOF_UNSIGNED_LONG_LONG==8)
typedef unsigned long long UINT64;
#else
typedef unsigned long long UINT64;
#endif
#endif

}; // sinsy

#endif // SINSY_UTIL_TYPES_H_
