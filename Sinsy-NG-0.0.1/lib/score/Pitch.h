/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_PITCH_H_
#define SINSY_PITCH_H_

#include <string>
#include <iostream>
#include "IStringable.h"

namespace sinsy
{

class Pitch
{
public:
   typedef int Step;
   static const Step C;
   static const Step Db;
   static const Step D;
   static const Step Eb;
   static const Step E;
   static const Step F;
   static const Step Gb;
   static const Step G;
   static const Step Ab;
   static const Step A;
   static const Step Bb;
   static const Step B;

   typedef int Octave;
   static const Step DEFAULT_STEP;
   static const Octave DEFAULT_OCTAVE;

   //! constructor
   Pitch();

   //! constructor
   Pitch(Step s, Octave o, int a = 0);

   //! constructor
   Pitch(const std::string& s, Octave o, int a = 0);

   //! copy constructor
   Pitch(const Pitch& obj);

   //! destructor
   virtual ~Pitch();

   //! assignment operator
   Pitch& operator=(const Pitch& obj);

   //! equal
   bool operator==(const Pitch& obj) const;

   //! not equrl
   bool operator!=(const Pitch& obj) const;

   //! set
   void set(Step s, Octave o, int alter = 0);

   //! set
   void set(const std::string& s, Octave o, int alter = 0);

   //! get step
   Step getStep() const;

   //! get octave
   Octave getOctave() const;

   //! get string of step
   const std::string& getStepStr() const;

   //! addition
   Pitch& operator+=(int i);

   //! subtraction
   Pitch& operator-=(int i);

   //! increment
   Pitch& operator++();

   //! decrement
   Pitch& operator--();

private:
   //! pitch step
   Step step;

   //! pitch octave
   Octave octave;
};

//! addition
Pitch operator+(const Pitch& pitch, int i);

//! subtraction
Pitch operator-(const Pitch& pitch, int i);

//! increment
Pitch operator++(const Pitch& pitch);

//! decrement
Pitch operator--(const Pitch& pitch);

//! to stream
std::ostream& operator<<(std::ostream&, const Pitch&);
};

#endif // SINSY_PITCH_H_
