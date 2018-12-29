/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_LABEL_STRINGS_H_
#define SINSY_LABEL_STRINGS_H_

#include <string>
#include <vector>
#include "ILabelOutput.h"

namespace sinsy
{

class LabelStrings : public ILabelOutput
{
public:
   //! constructor
   LabelStrings();

   //! destructor
   virtual ~LabelStrings();

   //! get size
   size_t size() const;

   //! get data
   const char* const* getData() const;

   //! output label
   virtual void output(const std::string& str);

private:
   //! copy constructor (donot use)
   LabelStrings(const LabelStrings&);

   //! assignment operator (donot use)
   LabelStrings& operator=(const LabelStrings&);

   typedef std::vector<char*> StringList;

   //! list of strings
   StringList stringList;
};

};

#endif // SINSY_LABEL_STRINGS_H_
