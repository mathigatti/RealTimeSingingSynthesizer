/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_XML_READER_H_
#define SINSY_XML_READER_H_

#include "ForEachAdapter.h"
#include "Beat.h"
#include "TempScore.h"
#include "XmlData.h"
#include "IScoreWriter.h"
#include "XmlParser.h"

namespace sinsy
{

class XmlReader : public IScoreWriter
{
public:
   //! constructor
   XmlReader();

   //! destructor
   virtual ~XmlReader();

   //! clear;
   void clear();

   //! write to score (operator << should be used)
   void write(IScoreWritable& writable) const;

   //! read xml from stream
   bool readXml(IReadableStream& stream);

   //! get xml data
   const XmlData* getXmlData() const;

private:
   //! copy constructor (donot use)
   XmlReader(const XmlReader&);

   //! assignment operator (donot use)
   XmlReader& operator=(const XmlReader&);

   //! initialize xml data
   void initXmlData();

   //! xml parser
   XmlParser parser;

   //! xml data
   XmlData* xmlData;

   //! encoding
   std::string encoding;

   //! part tag
   XmlData* part;
};

};

#endif // SINSY_XML_CONVERTER_H_
