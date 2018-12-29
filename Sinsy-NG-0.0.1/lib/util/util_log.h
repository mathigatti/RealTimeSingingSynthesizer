/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_UTIL_LOG_H_
#define SINSY_UTIL_LOG_H_

#include <iostream>
#include "util_types.h"

#define OUTPUTMSG(stream, type, x) stream<<"["<<type<<"] "<<x<<std::endl
#define LOG_MSG(x) OUTPUTMSG(std::cout, "LOG", x)
#define ERR_MSG(x) OUTPUTMSG(std::cerr, "ERR", x)
#define WARN_MSG(x) OUTPUTMSG(std::cerr, "WARN", x)
#define FUNC_NAME(x) __FUNCTION__<<'('<<x<<')'

#endif // SINSY_UTIL_LOG_H_
