/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_DELETER_H_
#define SINSY_DELETER_H_

#include "util_types.h"

namespace sinsy
{

/*!
 deleter
 */
template <class T>
class Deleter
{
public:

   //! constructor
   Deleter() {}

   //! destructor
   virtual ~Deleter() {}

   //! ...
   void operator()(T* pointer) {
      delete pointer;
   }
};

/*!
 pointer deleter
 */
template <class T>
class ArrayDeleter
{
public:

   //! constructor
   ArrayDeleter() {}

   //! destructor
   virtual ~ArrayDeleter() {}

   //! ...
   void operator()(T* pointer) {
      delete[] pointer;
   }
};

};

#endif // SINSY_DELETER_H_
