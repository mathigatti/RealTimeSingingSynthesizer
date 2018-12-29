/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_OUTPUT_FILE_H_
#define SINSY_OUTPUT_FILE_H_

#include <fstream>
#include "util_types.h"
#include "IWritableStream.h"

namespace sinsy
{

class OutputFile : public IWritableStream
{
public:
   //! constructor
   OutputFile();

   //! constructor
   explicit OutputFile(const std::string& fpath);

   //! destructor
   virtual ~OutputFile();

   //! write to stream
   size_t write(const void* buffer, size_t size) throw (StreamException);

   //! open
   void open(const std::string& fpath);

   //! close
   void close();

   //! stream is valid or not
   bool isValid() const;

private:
   //! copy constructor (donot use)
   OutputFile(const OutputFile&);

   //! assignment operator (donot use)
   OutputFile& operator=(const OutputFile&);

   //! stream
   std::ofstream stream;
};

};

#endif // SINSY_OUTPUT_FILE_H_
