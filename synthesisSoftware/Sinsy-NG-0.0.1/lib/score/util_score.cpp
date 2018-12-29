/* Created by Ghost Gloomy on 2018/11/8. */

#include "util_score.h"
#include "IScoreWriter.h"
#include "IScoreWritable.h"

namespace sinsy
{
/*!
 get measure duration
 */
size_t getMeasureDuration(const Beat& beat)
{
   return BASE_DIVISIONS * 4 * beat.getBeats() / beat.getBeatType();
}

/*!
 write score
 */
IScoreWritable& operator<<(IScoreWritable& writable, const IScoreWriter& writer)
{
   writer.write(writable);
   return writable;
}

/*!
 write score
 */
const IScoreWriter& operator>>(const IScoreWriter& writer, IScoreWritable& writable)
{
   writer.write(writable);
   return writer;
}

};  // namespace sinsy
