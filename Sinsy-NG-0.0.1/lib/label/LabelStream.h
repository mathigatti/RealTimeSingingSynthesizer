/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_LABEL_STREAM_H_
#define SINSY_LABEL_STREAM_H_

#include <string>
#include <fstream>
#include "ILabelOutput.h"

namespace sinsy
{

class LabelStream : public ILabelOutput
{
public:
   //! constructor
   explicit LabelStream(std::ostream& os);

   //! destructor
   virtual ~LabelStream();

   //! output label
   virtual void output(const std::string&);

private:
   //! copy constructor (donot use)
   LabelStream(const LabelStream&);

   //! assignment operator (donot use)
   LabelStream& operator=(const LabelStream&);

   //! stream
   std::ostream& stream;
};

};

#endif // SINSY_LABEL_STREAM_H_
