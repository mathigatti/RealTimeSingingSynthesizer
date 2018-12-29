/* Created by Ghost Gloomy on 2018/11/8. */
#ifndef SINSY_I_SCORE_WRITABLE_H_
#define SINSY_I_SCORE_WRITABLE_H_

#include <vector>
#include <string>
#include "Beat.h"
#include "Dynamics.h"
#include "Key.h"
#include "Note.h"

namespace sinsy
{

class IScoreWritable
{
public:
   //! destructor
   virtual ~IScoreWritable() {}

   // set encoding
   virtual void setEncoding(const std::string& encoding) = 0;

   //! change tempo
   virtual void changeTempo(double tempo) = 0;

   //! change beat
   virtual void changeBeat(const Beat& beat) = 0;

   //! change dynamics
   virtual void changeDynamics(const Dynamics& dynamics) = 0;

   //! change key
   virtual void changeKey(const Key& key) = 0;

   //! start crescendo
   virtual void startCrescendo() = 0;

   //! start diminuendo
   virtual void startDiminuendo() = 0;

   //! stop crescendo
   virtual void stopCrescendo() = 0;

   //! stop diminuendo
   virtual void stopDiminuendo() = 0;

   //! add note
   virtual void addNote(const Note& note) = 0;
};

};

#endif // SINSY_I_SCORE_WRITABLE_H_
