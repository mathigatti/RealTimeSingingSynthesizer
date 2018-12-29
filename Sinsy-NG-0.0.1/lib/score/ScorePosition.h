/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_SCORE_POSITION_H_
#define SINSY_SCORE_POSITION_H_

#include <iostream>

namespace sinsy
{

class ScorePosition
{
public:
   //! constructor
   ScorePosition();

   //! constructor
   explicit ScorePosition(size_t m);

   //! constructor
   ScorePosition(size_t m, size_t n, size_t d);

   //! copy constructor
   ScorePosition(const ScorePosition& obj);

   //! destructor
   virtual ~ScorePosition();

   //! assignment operator
   ScorePosition& operator=(const ScorePosition&);

   //! get measure
   size_t getMeasure() const;

   //! get numerator
   size_t getNumerator() const;

   //! get denominator
   size_t getDenominator() const;

private:
   //! measure index
   size_t measure;

   //! numerator
   size_t numerator;

   //! denominator
   size_t denominator;
};

//! to stream
std::ostream& operator<<(std::ostream&, const ScorePosition&);
};

#endif // SINSY_SCORE_POSITION_H_
