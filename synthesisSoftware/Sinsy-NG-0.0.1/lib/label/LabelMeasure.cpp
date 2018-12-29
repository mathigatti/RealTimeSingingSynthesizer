/* Created by Ghost Gloomy on 2018/11/8. */

#include "LabelMeasure.h"
#include "util_log.h"
#include "util_score.h"
#include "ScorePosition.h"

namespace sinsy
{

/*!
 constructor
 */
LabelMeasure::LabelMeasure(const Beat& b) : beat(b), index(0)
{
}

/*!
 destructor
 */
LabelMeasure::~LabelMeasure()
{
}

/*!
 add position
 */
void LabelMeasure::addPosition(const LabelPosition& p)
{
   position += p;
   maxPosition.setCount(position.getCount());
}

/*!
 get position
 */
const LabelPosition& LabelMeasure::getPosition() const
{
   return position;
}

/*!
 set max position
 */
void LabelMeasure::setMaxPosition(const LabelPosition& p)
{
   maxPosition = p;
   maxPosition.setCount(position.getCount());
}

/*!
 get max position
 */
const LabelPosition& LabelMeasure::getMaxPosition() const
{
   return maxPosition;
}

/*!
 get duration
 */
const sinsy::INT64 LabelMeasure::getDuration() const
{
   return BASE_DIVISIONS * 4 * beat.getBeats() / beat.getBeatType();
}

/*!
 set measure index
 */
void LabelMeasure::setIndex(size_t i)
{
   index = i;
}

/*!
 get measure index
 */
size_t LabelMeasure::getIndex() const
{
   return index;
}

};  // namespace sinsy
