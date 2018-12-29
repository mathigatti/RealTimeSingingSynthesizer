/* Created by Ghost Gloomy on 2018/11/8. */

#include <algorithm>
#include <stdexcept>

#include "Mode.h"
#include "util_log.h"
#include "util_string.h"

namespace sinsy
{

namespace
{
const int MODE_NUM = 2;
const std::string STR_MAJOR = "major";
const std::string STR_MINOR = "minor";
const std::string MODES[] = {STR_MAJOR, STR_MINOR};

class CompMode
{
public:
   //! constructor
   explicit CompMode(const std::string& str) : target(str) {}

   //! destructor
   virtual ~CompMode() {}

   //! ...
   bool operator()(const std::string& str) const {
      return (0 == target.compare(str)) ? true : false;
   }

   //! ...
   const std::string& target;
};

};

const Mode Mode::MAJOR(STR_MAJOR);
const Mode Mode::MINOR(STR_MINOR);

/*!
 constructor
 */
Mode::Mode() : value(0)
{
}

/*!
 constructor

 @param str mode
 */
Mode::Mode(const std::string& str)
{
   set(str);
}

/*!
 copy constructor
 */
Mode::Mode(const Mode& obj) : value(obj.value)
{
}

/*!
 destructor
 */
Mode::~Mode()
{
}

/*!
 assignment operator
 */
Mode& Mode::operator=(const Mode & obj)
{
   if (this != &obj) value = obj.value;
   return *this;
}

/*!
 equal operator
 */
bool Mode::operator==(const Mode& obj) const
{
   return (obj.value == this->value);
}

/*!
 not equal operator
 */
bool Mode::operator!=(const Mode& obj) const
{
   return !(obj == *this);
}

/*!
 set mode

 @param str mode
 */
void Mode::set(const std::string& str)
{
   std::string s(str);
   toLower(s);
   const std::string* itr(std::find_if(MODES, MODES + MODE_NUM, CompMode(s)));
   if (itr < MODES + MODE_NUM) {
      value = itr - MODES;
      return;
   }
   ERR_MSG("Unexpected mode : " << s);
   throw std::runtime_error("Mode::set() invalid argument");
}

/*!
 get mode

 @return mode
 */
const std::string& Mode::get() const
{
   return MODES[value];
}

/*!
 to stream
 */
std::ostream& operator<<(std::ostream& os, const Mode& mode)
{
   return os << mode.get();
}

};  // namespace sinsy
