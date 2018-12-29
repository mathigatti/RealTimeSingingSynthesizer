/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_MACRON_TABLE_H_
#define SINSY_MACRON_TABLE_H_

#include <map>
#include <vector>
#include <string>

namespace sinsy
{

class MacronTable
{
public:
   typedef std::vector<std::string> PhonemeList;

   //! constructor
   MacronTable();

   //! destructor
   virtual ~MacronTable();

   //! clear
   void clear();

   //! read from file
   bool read(const std::string& fname);

   //! divide phoneme set
   bool divide(const PhonemeList& src, PhonemeList& dst1, PhonemeList& dst2) const;

private:
   struct Result {
      PhonemeList forward;
      PhonemeList backward;
   };

   //! copy constructor (donot use)
   MacronTable(const MacronTable&);

   //! assignment operator (donot use)
   MacronTable& operator=(const MacronTable&);

   typedef std::map<PhonemeList, Result*> ConvertTable;

   //! type of convert table
   ConvertTable convertTable;
};

};

#endif // SINSY_MACRON_TABLE_H_
