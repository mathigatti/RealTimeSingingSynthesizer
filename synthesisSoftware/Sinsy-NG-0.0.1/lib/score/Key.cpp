/* Created by Ghost Gloomy on 2018/11/8. */

#include <algorithm>
#include <stdexcept>
#include "Key.h"
#include "util_log.h"
#include "util_string.h"

namespace sinsy
{

namespace
{

/*!
 adjust fifths
 */
size_t adjustFifths(int f)
{
   while (f < 0) {
      f += 12;
   }
   while (12 <= f) {
      f -= 12;
   }
   return static_cast<size_t>(f);
}

}; // namespace

/*!
 constructor
 */
Key::Key() : fifths(0), origFifths(0)
{
}

/*!
 constructor

 @param m mode
 @param f fifths
 */
Key::Key(const Mode& m, int f) : mode(m), fifths(adjustFifths(f)), origFifths(f)
{
}

/*!
 copy constructor
 */
Key::Key(const Key& obj) : mode(obj.mode), fifths(obj.fifths), origFifths(obj.origFifths)
{
}

/*!
 destructor
 */
Key::~Key()
{
}

/*!
 assignment operator
 */
Key& Key::operator=(const Key & obj)
{
   if (this != &obj) {
      this->mode = obj.mode;
      this->fifths = obj.fifths;
      this->origFifths = obj.origFifths;
   }
   return *this;
}

/*!
 equal operator
 */
bool Key::operator==(const Key& obj) const
{
   return (obj.mode == this->mode) && (obj.fifths == this->fifths) && (obj.origFifths == this->origFifths);
}

/*!
 not equal operator
 */
bool Key::operator!=(const Key& obj) const
{
   return !(obj == *this);
}

/*!
 get mode

 @return mode
 */
const Mode& Key::getMode() const
{
   return this->mode;
}

/*!
 get fifths

 @return fifths
 */
size_t Key::getFifths() const
{
   return this->fifths;
}

/*!
 get original fifths
 */
int Key::getOrigFifths() const
{
   return this->origFifths;
}


/*!
 set mode

 @param m mode
 */
void Key::setMode(const Mode& m)
{
   this->mode = m;
}

/*!
 set fifths
 */
void Key::setFifths(int f)
{
   this->origFifths = f;
   this->fifths = adjustFifths(f);
}

/*!
 to string
 */
std::ostream& operator<<(std::ostream& os, const Key& key)
{
   return os << "mode:" << key.getMode() << ", fifths:" << key.getFifths();
}

};  // namespace sinsy
