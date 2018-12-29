/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_DIPHTHONG_CONVERTER_H_
#define SINSY_DIPHTHONG_CONVERTER_H_

#include <map>
#include <vector>
#include <string>

namespace sinsy
{

class DiphthongConverter
{
public :

   //! constructor
   DiphthongConverter();

   //! destructor
   virtual ~DiphthongConverter();

   //! clear
   void clear();

   //! insert conversion rule
   bool insert(const std::string& diphthong, const std::string& front, const std::string& back);

   //! get front of converted phonemes
   std::string getFront(const std::string& diphthong) const;

   //! get back of converted phonemes
   std::string getBack(const std::string& diphthong) const;

private :
   //! copy constructor (donot use)
   DiphthongConverter(const DiphthongConverter&);

   //! assignment operator (donot use)
   DiphthongConverter& operator=(const DiphthongConverter&);

   typedef std::map<std::string, std::pair<std::string, std::string> > ConvMap;
   ConvMap convMap;
};

};

#endif // SINSY_DIPHTHONG_CONVERTER_H_
