/* Created by Ghost Gloomy on 2018/11/8. */

#include <vector>
#include <limits>
#include <stdexcept>
#include "SynthConditionImpl.h"

namespace sinsy
{

/*!
 constructor
 */
SynthConditionImpl::SynthConditionImpl() : playFlag(false), waveformBuffer(NULL)
{
}

/*!
 destructor
 */
SynthConditionImpl::~SynthConditionImpl()
{
}

/*!
 set play flag
 */
void SynthConditionImpl::setPlayFlag()
{
   this->playFlag = true;
}

/*!
 unset play flag
 */
void SynthConditionImpl::unsetPlayFlag()
{
   this->playFlag = false;
}

/*!
 set file path to save RIFF format file
 */
void SynthConditionImpl::setSaveFilePath(const std::string& filePath)
{
   this->saveFilePath = filePath;
}

/*!
 unset file path to save RIFF format file
 */
void SynthConditionImpl::unsetSaveFilePath()
{
   this->saveFilePath.clear();
}

/*!
 set waveform buffer
 */
void SynthConditionImpl::setWaveformBuffer(std::vector<double>& waveform)
{
   this->waveformBuffer = &waveform;
}

/*!
 unset waveform buffer
 */
void SynthConditionImpl::unsetWaveformBuffer()
{
   this->waveformBuffer = NULL;
}


};  // namespace sinsy
