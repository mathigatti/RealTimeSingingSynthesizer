/* Created by Ghost Gloomy on 2018/11/8. */

#include "InputFile.h"
#include "util_log.h"

namespace sinsy
{

/*!
 constructor
 */
InputFile::InputFile()
{
}

/*!
 constructor
 */
InputFile::InputFile(const std::string& fpath) : stream(fpath.c_str())
{
}

/*!
 destructor
 */
InputFile::~InputFile()
{
   stream.close();
}

/*!
 read data from stream

 @param buffer buffer for read data
 @param byte   byte you want to read
 @return       read bytes (0 : end of stream)
 */
size_t InputFile::read(void* buffer, size_t size) throw (StreamException)
{
   if(stream.fail()) {
      throw StreamException("InputFile::read()");
   }
   if (stream.eof()) {
      return 0;
   }
   stream.read(static_cast<char*>(buffer), size);
   int ret = stream.gcount();
   if (ret <= 0) {
      ERR_MSG("File reading error (size: " << size << ")  result of gcount = " << ret);
      throw StreamException("InputFile::read()");
   }
   return ret;
}

/*!
 open
 */
void InputFile::open(const std::string& fpath)
{
   stream.open(fpath.c_str());
}

/*!
 close
 */
void InputFile::close()
{
   stream.close();
}

/*!
 stream is valid or not
 */
bool InputFile::isValid() const
{
   return !stream.fail();
}

/*!
 read a line
 */
bool InputFile::readLine(std::string& line)
{
   if (!isValid() || isEof()) {
      return false;
   }
   getline(stream, line);
   return true;
}

};  // namespace sinsy
