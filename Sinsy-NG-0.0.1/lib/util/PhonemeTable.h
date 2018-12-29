/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_PHONEME_TABLE_H_
#define SINSY_PHONEME_TABLE_H_

#include <map>
#include <vector>
#include <string>

namespace sinsy
{

class PhonemeTable
{
public:
   typedef std::vector<std::string> PhonemeList;

   class Result
   {
   public:
      //! constructor
      Result();

      //! constructor
      Result(const std::string& s, const PhonemeList* p);

      //! copy constructor
      Result(const Result& obj);

      //! destructor
      virtual ~Result();

      //! assignment operator
      Result& operator=(const Result& obj);

      //! is valid or not
      bool isValid() const;

      //! get syllable
      const std::string& getSyllable() const;

      //! get phoneme list
      const PhonemeList* getPhonemeList() const;

      //! get mached length
      size_t getMatchedLength() const;

   private:
      //! syllable
      const std::string* syllable;

      //! phoneme list
      const PhonemeList* phonemeList;
   };

public:
   //! constructor
   PhonemeTable();

   //! destructor
   virtual ~PhonemeTable();

   //! clear
   void clear();

   //! read from file
   bool read(const std::string& fname);

   //! find from table
   Result find(const std::string& syllable) const;

   //! return matched result
   Result match(const std::string& syllable) const;

private:
   //! copy constructor (donot use)
   PhonemeTable(const PhonemeTable&);

   //! assignment operator (donot use)
   PhonemeTable& operator=(const PhonemeTable&);

   typedef std::map<std::string, PhonemeList*> ConvertTable;

   //! convert table
   ConvertTable convertTable;
};

};

#endif // SINSY_PHONEME_TABLE_H_
