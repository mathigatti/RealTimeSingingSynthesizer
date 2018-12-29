/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_SLUR_H_
#define SINSY_SLUR_H_

#include <string>
#include <vector>
#include <iostream>
#include "IStringable.h"

namespace sinsy
{

class Slur
{
public:
   //! constructor
   Slur();

   //! copy constructor
   Slur(const Slur& obj);

   //! destructor
   virtual ~Slur();

   //! assignment operator
   Slur& operator=(const Slur& obj);

   //! add start
   void addStart(int number);

   //! add stop
   void addStop(int number);

   //! no slur or not
   bool noSlur() const;

   //! merge to another slur
   void mergeTo(Slur& slur) const;

   //! clear
   void clear();

private:
   //! remove from start number list
   bool removeFromStartNumberList(int number);

   typedef std::vector<int> NumberList;

   //! start number list
   NumberList startNumberList;

   //! stop number list
   NumberList stopNumberList;

   friend std::ostream& operator<<(std::ostream& os, const Slur& slur);
};

//! to stream
std::ostream& operator<<(std::ostream& os, const Slur& slur);

}; // sinsy

#endif // SINSY_SLUR_H_
