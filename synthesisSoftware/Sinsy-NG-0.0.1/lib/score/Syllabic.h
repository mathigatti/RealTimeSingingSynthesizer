/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_SYLLABIC_H_
#define SINSY_SYLLABIC_H_

#include <string>

namespace sinsy
{

class Syllabic
{
public:
   static const Syllabic SINGLE;
   static const Syllabic BEGIN;
   static const Syllabic END;
   static const Syllabic MIDDLE;

   //! constructor
   Syllabic();

   //! constructor
   explicit Syllabic(const std::string& str);

   //! copy constructor
   Syllabic(const Syllabic& obj);

   //! destructor
   virtual ~Syllabic();

   //! assignment operator
   Syllabic& operator=(const Syllabic& obj);

   //! equal
   bool operator==(const Syllabic& obj) const;

   //! not equal
   bool operator!=(const Syllabic& obj) const;

   //! set syllabic
   void set(const std::string& s);

   //! get syllabic
   const std::string& get() const;

private:
   //! value
   size_t value;
};

//! to stream
std::ostream& operator<<(std::ostream& os, const Syllabic& syllabic);
};

#endif // SINSY_SYLLABIC_H_
