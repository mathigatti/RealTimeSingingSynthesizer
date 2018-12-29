/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_SYNTH_CONDITION_IMPL_H_
#define SINSY_SYNTH_CONDITION_IMPL_H_

#include <string>

namespace sinsy
{

class SynthConditionImpl
{
public:
   //! constructor
   SynthConditionImpl();

   //! destructor
   virtual ~SynthConditionImpl();

   //! set play flag
   void setPlayFlag();

   //! unset play flag
   void unsetPlayFlag();

   //! set file path to save RIFF format file
   void setSaveFilePath(const std::string& filePath);

   //! unset file path to save RIFF format file
   void unsetSaveFilePath();

   //! set waveform buffer
   void setWaveformBuffer(std::vector<double>& waveform);

   //! unset waveform buffer
   void unsetWaveformBuffer();


private:
   //! copy constructor (donot use)
   SynthConditionImpl(const SynthConditionImpl&);

   //! assignment operator (donot use)
   SynthConditionImpl& operator=(const SynthConditionImpl&);

   //! play flag
   bool playFlag;

   // ! file path to save wave data
   std::string saveFilePath;

   //! buffer for wave data
   std::vector<double>* waveformBuffer;

   friend class HtsEngine;
};

};

#endif // SINSY_SYNTH_CONDITION_IMPL_H_
