/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_I_NOTE_LABEL_H_
#define SINSY_I_NOTE_LABEL_H_

namespace sinsy
{

class INoteLabel
{
public:
   //! destructor
   virtual ~INoteLabel() {}

   //! set absolute pitch
   virtual void setAbsolutePitch(const Pitch&) = 0;

   //! set relative pitch
   virtual void setRelativePitch(size_t) = 0;

   //! set key
   virtual void setKey(size_t) = 0;

   //! set beat
   virtual void setBeat(const Beat&) = 0;

   //! set tempo
   virtual void setTempo(double) = 0;

   //! set number of syllables
   virtual void setSyllableNum(size_t) = 0;

   //! set length
   virtual void setLength(const LabelPosition&) = 0;

   //! set position in measure
   virtual void setPositionInMeasure(const LabelPosition&, const LabelPosition&) = 0;

   //! set position in phrase
   virtual void setPositionInPhrase(const LabelPosition&, const LabelPosition&) = 0;

   //! set slur from previous note
   virtual void setSlurFromPrev(bool) = 0;

   //! set slur to next note
   virtual void setSlurToNext(bool) = 0;

   //! set dynamics
   virtual void setDynamics(const Dynamics&) = 0;

   //! set length from previous accent
   virtual void setLengthFromPrevAccent(const LabelPosition&) = 0;

   //! set length to next accent
   virtual void setLengthToNextAccent(const LabelPosition&) = 0;

   //! set length from previous staccato
   virtual void setLengthFromPrevStaccato(const LabelPosition&) = 0;

   //! set length to next staccato
   virtual void setLengthToNextStaccato(const LabelPosition&) = 0;

   //! set position in crescendo
   virtual void setPositionInCrescendo(const LabelPosition&, const LabelPosition&) = 0;

   //! set position in diminuendo
   virtual void setPositionInDiminuendo(const LabelPosition&, const LabelPosition&) = 0;

   //! set pitch difference from previous note
   virtual void setPitchDifferenceFromPrev(int) = 0;

   //! set pitch difference to next note
   virtual void setPitchDifferenceToNext(int) = 0;

   //! set breath between previous and this notes
   virtual void setBreathFromPrev(bool) = 0;

   //! set breath between this and next notes
   virtual void setBreathToNext(bool) = 0;

   //! set previous phrase info
   virtual void setPrevPhraseInfo(size_t, size_t) = 0;

   //! set phrase info
   virtual void setPhraseInfo(size_t, size_t) = 0;

   //! set next phrase info
   virtual void setNextPhraseInfo(size_t, size_t) = 0;
};

};

#endif // SINSY_I_NOTE_LABEL_H_
