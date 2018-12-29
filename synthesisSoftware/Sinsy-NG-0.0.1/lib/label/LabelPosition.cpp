/* Created by Ghost Gloomy on 2018/11/8. */

#include "LabelPosition.h"
#include "ScorePosition.h"
#include "util_log.h"
#include "util_score.h"

namespace sinsy
{

/*!
 constructor
 */
LabelPosition::LabelPosition() : count(0), time(0.0), point(0), duration(0)
{
}

/*!
 constructor
 */
LabelPosition::LabelPosition(size_t dur, double tempo) : count(0), time(0.0), point(0), duration(0)
{
   add(dur, tempo);
}

/*!
 copy constructor
 */
LabelPosition::LabelPosition(const LabelPosition& obj) : count(obj.count), time(obj.time), point(obj.point), duration(obj.duration)
{
}

/*!
 destructor
 */
LabelPosition::~LabelPosition()
{
}

/*!
 assignment operator
 */
LabelPosition& LabelPosition::operator=(const LabelPosition & obj)
{
   if (&obj != this) {
      count = obj.count;
      time = obj.time;
      point = obj.point;
      duration = obj.duration;
   }
   return *this;
}

/*!
 operator +=
 */
LabelPosition& LabelPosition::operator+=(const LabelPosition & obj)
{
   count += obj.count;
   time += obj.time;
   point += obj.point;
   duration += obj.duration;
   return *this;
}

/*!
 operator -=
 */
LabelPosition& LabelPosition::operator-=(const LabelPosition & obj)
{
   count -= obj.count;
   time -= obj.time;
   point -= obj.point;
   duration -= obj.duration;
   return *this;
}

/*!
 operator +
 */
LabelPosition LabelPosition::operator+(const LabelPosition& obj) const
{
   LabelPosition ret(*this);
   ret += obj;
   return ret;
}

/*!
 operator -
 */
LabelPosition LabelPosition::operator-(const LabelPosition& obj) const
{
   LabelPosition ret(*this);
   ret -= obj;
   return ret;
}

/*!
 add
 */
void LabelPosition::add(size_t dur, double tempo)
{
   double  t(dur * 60 / (BASE_DIVISIONS * tempo));
   size_t p(dur * 24);

   ++count;
   time += t;
   point += p;
   duration += dur;
}

/*!
 set count
 */
void LabelPosition::setCount(size_t c)
{
   count = c;
}

/*!
 get count
 */
sinsy::INT64 LabelPosition::getCount() const
{
   return count;
}

/*!
 get time
 */
double LabelPosition::getTime() const
{
   return time;
}

/*!
 get point
 */
sinsy::INT64 LabelPosition::getPoint() const
{
   return static_cast<INT64>(point / BASE_DIVISIONS);
}

/*!
 get duration
 */
sinsy::INT64 LabelPosition::getDuration() const
{
   return duration;
}

/*!
 to stream
 */
std::ostream& operator<<(std::ostream& os, const LabelPosition& obj)
{
   os << "count:" << obj.getCount() << ", time:" << obj.getTime() << ", point:" << obj.getPoint() << ", duration:" << obj.getDuration();
   return os;
}

};  // namespace sinsy
