/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_KEY_H_
#define SINSY_KEY_H_

#include <string>
#include <iostream>
#include "IStringable.h"
#include "Mode.h"

namespace sinsy
{

class Key
{
public:
   //! constructor
   Key();

   //! constructor
   Key(const Mode& mode,  int fifths);

   //! copy constructor
   Key(const Key& obj);

   //! destructor
   virtual ~Key();

   //! assignment operator
   Key& operator=(const Key& obj);

   //! equal
   bool operator==(const Key& obj) const;

   //! not equal
   bool operator!=(const Key& obj) const;

   //! get mode
   const Mode& getMode() const;

   //! get fifths
   size_t getFifths() const;

   //! get original fifths
   int getOrigFifths() const;

   //! set mode
   void setMode(const Mode& mode);

   //! set fifths
   void setFifths(int fifths);

private:
   //! mode
   Mode mode;

   //! fifths
   size_t fifths;

   //! original fifths
   int origFifths;
};

//! to string
std::ostream& operator<<(std::ostream& os, const Key& key);
};

#endif // SINSY_KEY_H_
