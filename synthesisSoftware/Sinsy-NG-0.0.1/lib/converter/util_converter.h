/* Created by Ghost Gloomy on 2018/11/8. */
/* ----------------------------------------------------------------- */

#ifndef SINSY_UTIL_CONVERTER_H_
#define SINSY_UTIL_CONVERTER_H_

#include <vector>
#include <string>
#include "util_types.h"
#include "PhonemeTable.h"

namespace sinsy
{
typedef UINT8 ScoreFlag;


const std::string DEFAULT_SIL_STR = "sil";
const std::string DEFAULT_PAU_STR = "pau";

class MultibyteCharRange;

//! analyze score flags
ScoreFlag analyzeScoreFlags(std::string& str, const MultibyteCharRange* = NULL);

std::string restoreScoreFlag(ScoreFlag flag);

bool isEnableFlag(ScoreFlag flag);

std::string getScoreFlagStr(ScoreFlag flag);

ScoreFlag& setDisableFlag(ScoreFlag& flag);

ScoreFlag& unsetDisableFlag(ScoreFlag& flag);

ScoreFlag& setFalsettoFlag(ScoreFlag& flag);

};

#endif // SINSY_UTIL_CONVERTER_H_
