/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_MODE_H_
#define SINSY_MODE_H_

#include <string>
#include <iostream>
#include "IStringable.h"

namespace sinsy
{

class Mode
{
public:
   static const Mode MAJOR;
   static const Mode MINOR;

   //! constructor
   Mode();

   //! constructor
   explicit Mode(const std::string& str);

   //! copy constructor
   Mode(const Mode& obj);

   //! destructor
   virtual ~Mode();

   //! assignment operator
   Mode& operator=(const Mode& obj);

   //! equal
   bool operator==(const Mode& obj) const;

   //! not equal
   bool operator!=(const Mode& obj) const;

   //! set mode
   void set(const std::string& str);

   //! get mode
   const std::string& get() const;

private:
   //! value
   size_t value;
};

//! to stream
std::ostream& operator<<(std::ostream& os, const Mode& mode);
};

#endif // SINSY_MODE_H_
