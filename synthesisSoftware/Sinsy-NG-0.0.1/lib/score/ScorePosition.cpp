/* Created by Ghost Gloomy on 2018/11/8. */

#include "ScorePosition.h"

namespace sinsy
{

/*!
 constructor
 */
ScorePosition::ScorePosition() : measure(0), numerator(0), denominator(0)
{
}

/*!
 constructor
 */
ScorePosition::ScorePosition(size_t m) : measure(m), numerator(0), denominator(0)
{
}

/*!
 constructor
 */
ScorePosition::ScorePosition(size_t m, size_t n, size_t d) : measure(m), numerator(n), denominator(d)
{
}

/*!
 copy constructor
 */
ScorePosition::ScorePosition(const ScorePosition& obj) : measure(obj.measure), numerator(obj.numerator), denominator(obj.denominator)
{
}

/*!
 destructor
 */
ScorePosition::~ScorePosition()
{
}

/*!
 assignment operator
 */
ScorePosition& ScorePosition::operator=(const ScorePosition & obj)
{
   this->measure = obj.measure;
   this->numerator = obj.numerator;
   this->denominator = obj.denominator;
   return *this;
}

/*!
 get measure
 */
size_t ScorePosition::getMeasure() const
{
   return measure;
}

/*!
 get numerator
 */
size_t ScorePosition::getNumerator() const
{
   return numerator;
}

/*!
 get denominator
 */
size_t ScorePosition::getDenominator() const
{
   return denominator;
}

/*!
 to stream
 */
std::ostream& operator<<(std::ostream& os, const ScorePosition& position)
{
   return os << position.getMeasure() << " : " << position.getNumerator() << "/" << position.getDenominator();
}

};  // namespace sinsy
