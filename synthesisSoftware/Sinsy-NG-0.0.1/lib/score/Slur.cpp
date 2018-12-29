/* Created by Ghost Gloomy on 2018/11/8. */

#include <algorithm>
#include "util_log.h"
#include "Slur.h"

namespace sinsy
{

/*!
 constructor
 */
Slur::Slur()
{
}

/*!
 copy constructor
 */
Slur::Slur(const Slur& obj)
{
   *this = obj;
}

/*!
 destructor
 */
Slur::~Slur()
{
}

/*!
 assignment operator
 */
Slur& Slur::operator=(const Slur & obj)
{
   if (this != &obj) {
      this->startNumberList = obj.startNumberList;
      this->stopNumberList = obj.stopNumberList;
   }
   return *this;
}

/*!
 add start
 */
void Slur::addStart(int number)
{
   NumberList::iterator itr(std::find(startNumberList.begin(), startNumberList.end(), number));
   if (startNumberList.end() == itr) {
      startNumberList.push_back(number);
   }
}

/*!
 @internal
 remove from start number list

 @param number target slur number
 @return whether the number was contained in start number list or not
 */
bool Slur::removeFromStartNumberList(int number)
{
   NumberList::iterator itr(std::find(startNumberList.begin(), startNumberList.end(), number));
   if (startNumberList.end() == itr) { // not contained in start number list
      return false;
   }
   startNumberList.erase(itr);
   return true;
}

/*!
 add stop
 */
void Slur::addStop(int number)
{
   bool exist(removeFromStartNumberList(number));

   NumberList::iterator itr(std::find(stopNumberList.begin(), stopNumberList.end(), number));
   if (!exist && (stopNumberList.end() == itr)) {
      stopNumberList.push_back(number);
   } else if (exist && (stopNumberList.end() != itr)) {
      stopNumberList.erase(itr);
   }
}

/*!
 no slur or not
 */
bool Slur::noSlur() const
{
   if (startNumberList.empty() && stopNumberList.empty()) {
      return true;
   }
   return false;
}

/*!
 merge to another slur
 */
void Slur::mergeTo(Slur& slur) const
{
   {
      const NumberList::const_iterator itrEnd(this->stopNumberList.end());
      for (NumberList::const_iterator itr(this->stopNumberList.begin()); itrEnd != itr; ++itr) {
         slur.addStop(*itr);
      }
   }
   {
      const NumberList::const_iterator itrEnd(this->startNumberList.end());
      for (NumberList::const_iterator itr(this->startNumberList.begin()); itrEnd != itr; ++itr) {
         slur.addStart(*itr);
      }
   }
}

/*!
 clear
 */
void Slur::clear()
{
   startNumberList.clear();
   stopNumberList.clear();
}

/*!
 to stream
 */
std::ostream& operator<<(std::ostream& os, const Slur& slur)
{

   {
      os << "Start: ";
      const Slur::NumberList::const_iterator itrEnd(slur.startNumberList.end());
      for (Slur::NumberList::const_iterator itr(slur.startNumberList.begin()); itrEnd != itr; ++itr) {
         if (slur.startNumberList.begin() != itr) {
            os << ", ";
         }
         os << (*itr);
      }
   }
   os << ", ";
   {
      os << "Stop: ";
      const Slur::NumberList::const_iterator itrEnd(slur.stopNumberList.end());
      for (Slur::NumberList::const_iterator itr(slur.stopNumberList.begin()); itrEnd != itr; ++itr) {
         if (slur.stopNumberList.begin() != itr) {
            os << ", ";
         }
         os << (*itr);
      }
   }
   return os;
}

};  // namespace sinsy
