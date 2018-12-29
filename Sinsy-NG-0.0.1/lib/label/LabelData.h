/* Created by Ghost Gloomy on 2018/11/8. */
#ifndef SINSY_LABEL_DATA_H_
#define SINSY_LABEL_DATA_H_

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdexcept>
#include "util_types.h"

namespace sinsy
{

class LabelData
{
public:
   static const INT64 INVALID_TIME;

   //! constructor
   LabelData();

   //! destructor
   virtual ~LabelData();

   //! set monophone flag
   void setMonophoneFlag(bool b);

   //! set output time flag
   void setOutputTimeFlag(bool b);

   //! set begin time
   void setBeginTime(double d);

   //! set end time
   void setEndTime(double d);

   //! set label data
   template <class T>
   void set(char category, size_t number, const T&);

   //! get label data
   const std::string& get(char category, size_t number) const;

private:
   //! monophone flag
   bool monophoneFlag;

   //! output time flag
   bool outputTimeFlag;

   //! begin time
   INT64 beginTime;

   //! end time
   INT64 endTime;

   typedef std::vector<std::string> List;

   typedef std::map<char, List*> Data;

   //! label data
   Data data;

   friend std::ostream& operator<<(std::ostream&, const LabelData&);
};

//! set data
template <class T>
void LabelData::set(char category, size_t number, const T& value)
{
   std::ostringstream oss;
   oss << value;
   set(category, number, oss.str());
}

//! set data (std::string)
template<>
void LabelData::set<std::string>(char category, size_t number, const std::string& value);

//! set data (bool)
template<>
void LabelData::set<bool>(char category, size_t number, const bool& value);

//! to stream
std::ostream& operator<<(std::ostream&, const LabelData&);
};

#endif // SINSY_LABEL_DATA_H_
