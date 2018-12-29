/* Created by Ghost Gloomy on 2018/11/8. */

#include <stdexcept>
#include "Beat.h"

namespace sinsy
{

namespace
{
const size_t DEFAULT_BEATS = 4;
const size_t DEFAULT_BEAT_TYPE = 4;
};

/*!
 constructor
 */
Beat::Beat() : beats(DEFAULT_BEATS), beatType(DEFAULT_BEAT_TYPE)
{}

/*!
 constructor
 */
Beat::Beat(size_t b, size_t t)
{
   setBeats(b);
   setBeatType(t);
}

/*!
 copy constructor
 */
Beat::Beat(const Beat& obj) : beats(obj.beats), beatType(obj.beatType)
{
}

/*!
 destructor
 */
Beat::~Beat()
{
}

/*!
 assignment operator
 */
Beat& Beat::operator=(const Beat & obj)
{
   this->beats = obj.beats;
   this->beatType = obj.beatType;
   return *this;
}

/*!
 get beats
 */
size_t Beat::getBeats() const
{
   return this->beats;
}

/*!
 get beat type
 */
size_t Beat::getBeatType() const
{
   return this->beatType;
}

/*!
 set beats
 */
void Beat::setBeats(size_t b)
{
   if (b <= 0) {
      throw std::range_error("Beat::setBeats() invalid value");
   }
   this->beats = b;
}

/*!
 set beat type
 */
void Beat::setBeatType(size_t b)
{
   if (b <= 0) {
      throw std::range_error("Beat::setBeatType() invalid value");
   }
   this->beatType = b;
}

/*!
 to string
 */
std::ostream& operator<<(std::ostream& os, const Beat& beat)
{
   return os << beat.getBeats() << "/" << beat.getBeatType();
}

};  // namespace sinsy
