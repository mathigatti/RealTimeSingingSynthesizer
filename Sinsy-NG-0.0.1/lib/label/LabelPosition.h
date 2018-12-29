/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_LABEL_POSITION_H_
#define SINSY_LABEL_POSITION_H_

#include <fstream>
#include "util_types.h"

namespace sinsy
{

class LabelPosition
{
public:
   //! constructor
   LabelPosition();

   //! constructor
   LabelPosition(size_t dur, double tempo);

   //! copy constructor
   LabelPosition(const LabelPosition& obj);

   //! destructor
   virtual ~LabelPosition();

   //! assignment operator
   LabelPosition& operator=(const LabelPosition& obj);

   //! operator +=
   LabelPosition& operator+=(const LabelPosition& obj);

   //! operator -=
   LabelPosition& operator-=(const LabelPosition& obj);

   //! operator +
   LabelPosition operator+(const LabelPosition&) const;

   //! operator -
   LabelPosition operator-(const LabelPosition&) const;

   //! add
   void add(size_t dur, double tempo);

   //! set count
   void setCount(size_t c);

   //! get count
   INT64 getCount() const;

   //! get time
   double getTime() const;

   //! get point
   INT64 getPoint() const;

   //! get duration
   INT64 getDuration() const;

private:
   //! count
   INT64 count;

   //! time (1sec = 1.0)
   double time;

   //! point (1/32 pitch = 3)
   INT64 point;

   //! duration
   INT64 duration;
};

//! to stream
std::ostream& operator<<(std::ostream&, const LabelPosition&);

};

#endif // SINSY_LABEL_POSITION_H_
