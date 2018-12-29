/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_LABEL_MEASURE_H_
#define SINSY_LABEL_MEASURE_H_

#include "util_types.h"
#include "LabelPosition.h"
#include "Beat.h"

namespace sinsy
{

class LabelMeasure
{
public:
   //! constructor
   LabelMeasure(const Beat& b);

   //! destructor
   virtual ~LabelMeasure();

   //! add position
   void addPosition(const LabelPosition&);

   //! get position
   const LabelPosition& getPosition() const;

   //! set max position
   void setMaxPosition(const LabelPosition&);

   //! get max position
   const LabelPosition& getMaxPosition() const;

   //! get duration
   const INT64 getDuration() const;

   //! set measure index
   void setIndex(size_t i);

   //! get measure index
   size_t getIndex() const;

private:
   //! copy constructor (donot use)
   LabelMeasure(const LabelMeasure&);

   //! assignment operator (donot use)
   LabelMeasure& operator=(const LabelMeasure&);

   //! beat
   Beat beat;

   //! position
   LabelPosition position;

   //! max position
   LabelPosition maxPosition;

   //! measure index
   size_t index;
};

};

#endif // SINSY_LABEL_MEASURE_H_
