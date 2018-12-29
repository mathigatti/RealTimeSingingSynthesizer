/* Created by Ghost Gloomy on 2018/11/8. */

#include "util_log.h"
#include "OutputFile.h"

namespace sinsy
{

/*!
 constructor
 */
OutputFile::OutputFile()
{
}

/*!
 constructor
 */
OutputFile::OutputFile(const std::string& fpath) : stream(fpath.c_str())
{
}

/*!
 destructor
 */
OutputFile::~OutputFile()
{
   stream.close();
}

/*!
 write data to stream
 @param buffer buffer for data that you want to write
 @param byte   byte you want to write
 @return       write bytes
 */
size_t OutputFile::write(const void* buffer, size_t size) throw (StreamException)
{
   if (stream.fail()) {
      throw StreamException("OutputFile::write()");
   }
   stream.write(static_cast<const char*>(buffer), size);
   if (stream.fail()) {
      ERR_MSG("File writing error (size: " << size << ")");
      throw StreamException("OutputFile::write()");
   }
   return size;
}

/*!
 open
 */
void OutputFile::open(const std::string& fpath)
{
   stream.open(fpath.c_str());
}

/*!
 close
 */
void OutputFile::close()
{
   stream.close();
}

/*!
 stream is valid or not
 */
bool OutputFile::isValid() const
{
   return !stream.fail();
}

};  // namespace sinsy
