/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_XML_DATA_H_
#define SINSY_XML_DATA_H_

#include <vector>
#include <map>
#include <string>
#include "StreamException.h"
#include "IStringable.h"
#include "Beat.h"

namespace sinsy
{

class IReadableStream;

class XmlData : public IStringWritable
{
public:
   typedef std::vector<XmlData*> Children;

   //! constructor
   XmlData(const std::string& t, const std::string& d = "");

   //! copy constructor
   XmlData(const XmlData&);

   //! destructor
   virtual ~XmlData();

   //! get tag
   const std::string& getTag() const;

   //! get data
   const std::string& getData() const;

   //! set data
   void setData(const std::string& str);

   //! add child
   Children::iterator addChild(XmlData* child);

   //! erase child
   XmlData::Children::iterator eraseChild(const Children::iterator& itr);

   //! add attribute
   bool addAttribute(const std::string& k, const std::string& v);

   //! get attribute
   const std::string& getAttribute(const std::string& k) const;

   //! push into stringstream
   std::ostream& toStringStream(std::ostream& os) const;

   //! get begin const iterator of children
   Children::const_iterator childBegin() const;

   //! get end const iterator of children
   Children::const_iterator childEnd() const;

   //! get begin iterator of children
   Children::iterator childBegin();

   //! get end iterator of children
   Children::iterator childEnd();

private:
   //! assignment operator (donot use)
   XmlData& operator=(const XmlData&);

   //! tag
   std::string tag;

   //! data
   std::string data;

   //! children
   Children children;

   typedef std::map<std::string, std::string> Attributes;

   //! attributes
   Attributes attributes;
};

};

#endif // SINSY_XML_DATA_H_
