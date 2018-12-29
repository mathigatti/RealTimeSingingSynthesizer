/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_XML_PARSER_H_
#define SINSY_XML_PARSER_H_

#include <vector>
#include <string>
#include "XmlData.h"

namespace sinsy
{

class XmlParser
{
public:
   //! constructor
   XmlParser();

   //! destructor
   virtual ~XmlParser();

   //! read xml from stream
   XmlData* read(IReadableStream& stream, std::string& encoding) throw (StreamException);

private:
   //! copy constructor (donot use)
   XmlParser(const XmlParser&);

   //! assignment operator (donot use)
   XmlParser& operator=(const XmlParser&);
};

};

#endif // SINSY_XML_PARSER_H_
