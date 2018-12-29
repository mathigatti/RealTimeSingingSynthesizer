/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_I_LABEL_OUTPUT_H_
#define SINSY_I_LABEL_OUTPUT_H_

#include <string>

namespace sinsy
{

class ILabelOutput
{
public:
   //! destructor
   virtual ~ILabelOutput() {}

   //! output
   virtual void output(const std::string& str) = 0;
};

};

#endif // SINSY_I_LABEL_OUTPUT_H_
