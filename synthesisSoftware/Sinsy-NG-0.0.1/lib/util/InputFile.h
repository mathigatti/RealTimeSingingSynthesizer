/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_INPUT_FILE_H_
#define SINSY_INPUT_FILE_H_

#include <fstream>
#include "util_types.h"
#include "IReadableStream.h"

namespace sinsy
{

class InputFile : public IReadableStream
{
public:
   //! constructor
   InputFile();

   //! constructor
   explicit InputFile(const std::string& fpath);

   //! destructor
   virtual ~InputFile();

   //! read from stream
   size_t read(void* buffer, size_t size) throw (StreamException);

   //! open
   void open(const std::string& fpath);

   //! close
   void close();

   //! stream is valid or not
   bool isValid() const;

   //! stream is end of file
   inline bool isEof() const {
      return stream.eof();
   }

   //! read a line
   bool readLine(std::string& line);

private:
   //! copy constructor (donot use)
   InputFile(const InputFile&);

   //! assignment operator (donot use)
   InputFile& operator=(const InputFile&);

   //! stream
   std::ifstream stream;
};

};

#endif // SINSY_INPUT_FILE_H_
