/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_BEAT_H_
#define SINSY_BEAT_H_

#include <iostream>

namespace sinsy
{

class Beat
{
public:
   //! constructor
   Beat();

   //! constructor
   Beat(size_t b, size_t t);

   //! copy constructor
   Beat(const Beat& obj);

   //! destructor
   virtual ~Beat();

   //! assignment operator
   Beat& operator=(const Beat& obj);

   //! get beats
   size_t getBeats() const;

   //! get beat type
   size_t getBeatType() const;

   //! set beats
   void setBeats(size_t b);

   //! set beat type
   void setBeatType(size_t b);

private:
   //! beats
   size_t beats;

   //! beat type
   size_t beatType;
};

//! to string
std::ostream& operator<<(std::ostream&, const Beat&);

};

#endif // SINSY_BEAT_H_
