/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_UTIL_SCORE_H_
#define SINSY_UTIL_SCORE_H_

#include <cstddef>

namespace sinsy
{
class IScoreWriter;
class IScoreWritable;
class Beat;

const size_t BASE_DIVISIONS = 960;
const double DEFAULT_TEMPO = 100.0;

//! get measure duration
size_t getMeasureDuration(const Beat& beat);

//! write score
IScoreWritable& operator<<(IScoreWritable& writable, const IScoreWriter& writer);

//! write score
const IScoreWriter& operator>>(const IScoreWriter& writer, IScoreWritable& writable);

};

#endif // SINSY_UTIL_SCORE_H_
