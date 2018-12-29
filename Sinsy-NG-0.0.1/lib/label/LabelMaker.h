/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_LABEL_MAKER_H_
#define SINSY_LABEL_MAKER_H_

#include <string>
#include <vector>
#include <deque>
#include "IScoreWritable.h"
#include "Beat.h"
#include "Dynamics.h"
#include "Mode.h"
#include "IConvertable.h"
#include "Converter.h"
#include "IConf.h"
#include "TempScore.h"
#include "NoteLabeler.h"
#include "SyllableLabeler.h"
#include "PhonemeLabeler.h"
#include "LabelData.h"
#include "ILabelOutput.h"
#ifdef HAVE_HTS
#include "SynthConditionImpl.h"
#endif

namespace sinsy
{

class LabelMaker : public IScoreWritable
{
public:
   //! constructor
   explicit LabelMaker(Converter& converter, bool sepRests = true);

   //! destructor
   virtual ~LabelMaker();

   //! set encoding
   virtual void setEncoding(const std::string& e);

   //! change tempo
   virtual void changeTempo(double t);

   //! change beat
   virtual void changeBeat(const Beat& b);

   //! change dynamics
   virtual void changeDynamics(const Dynamics& d);

   //! change key
   virtual void changeKey(const Key& k);

   //! start crescendo
   virtual void startCrescendo();

   //! start diminuendo
   virtual void startDiminuendo();

   //! stop crescendo
   virtual void stopCrescendo();

   //! stop diminuendo
   virtual void stopDiminuendo();

   //! add note
   virtual void addNote(const Note& note);

   //! fix
   void fix();

   //! output label
   void outputLabel(ILabelOutput& output, bool monophoneFlag = false, int overwriteEnableFlag = 0, int timeFlag = 0) const;

private:
   //! copy constructor (donot use)
   LabelMaker(const LabelMaker&);

   //! assignment operator (donot use)
   LabelMaker& operator=(const LabelMaker&);

   //! get last measure
   LabelMeasure* getLastMeasure();

   //! converter
   Converter& converter;

   //! encoding of lyrics
   std::string encoding;

   //! ...
   bool separateWholeNoteRests;

   //! is fixed or not
   bool isFixed;

   //! temporary score
   TempScore tempScore;

   //! tempo
   double tempo;

   //! key
   Key key;

   //! beat
   Beat beat;

   //! dynamics
   Dynamics dynamics;

   //! number of syllables
   size_t syllableNum;

   //! in tie
   bool inTie;

   //! in crescendo
   bool inCrescendo;

   //! in diminuendo
   bool inDiminuendo;

   //! position of measure
   LabelPosition measurePosition;

   //! duration of residual measure
   int residualMeasureDuration;

   typedef std::deque<LabelMeasure*> MeasureQue;

   //! stock of measures
   MeasureQue stockMeasures;

   typedef std::vector<LabelMeasure*> MeasureList;

   //! list of measures
   MeasureList measureList;

   typedef std::vector<NoteGroup*> NoteGroupList;

   //! list of phrases
   NoteGroupList phraseList;

   //! list of crescendos
   NoteGroupList crescendoList;

   //! list of diminuendos
   NoteGroupList diminuendoList;

   typedef std::vector<NoteLabeler*> NoteList;

   //! list of notes
   NoteList noteList;

   typedef NoteList::const_iterator ConstNoteItr;

   //! move to previous note
   bool moveToPrevNote(ConstNoteItr& nItr, bool skipRests) const;

   //! move to next note
   bool moveToNextNote(ConstNoteItr& nItr, bool skipRests) const;

   typedef NoteLabeler::List::const_iterator ConstSyllableItr;

   //! move to previous syllable
   bool moveToPrevSyllable(ConstNoteItr& nItr, ConstSyllableItr& sItr, bool skipRests) const;

   //! move to next syllable
   bool moveToNextSyllable(ConstNoteItr& nItr, ConstSyllableItr& sItr, bool skipRests) const;

   typedef SyllableLabeler::List::const_iterator ConstPhonemeItr;

   //! move to previous phoneme
   bool moveToPrevPhoneme(ConstNoteItr& nItr, ConstSyllableItr& sItr, ConstPhonemeItr& pItr, bool skipRests) const;

   //! move to next phoneme
   bool moveToNextPhoneme(ConstNoteItr& nItr, ConstSyllableItr& sItr, ConstPhonemeItr& pItr, bool skipRests) const;

   //! set label data
   void setLabelData(LabelData& label, const ConstNoteItr& noteItr, const ConstSyllableItr& syllableItr, const ConstPhonemeItr& phonemeItr, int overwriteEnableFlag, int timeFlag) const;

   //! apply stocks
   void applyStocks();
};

};

#endif // SINSY_LABEL_MAKER_H_
