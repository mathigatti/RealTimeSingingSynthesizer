/* Created by Ghost Gloomy on 2018/11/8. */

#include <algorithm>

#include "TempScore.h"
#include "util_score.h"
#include "Deleter.h"

namespace sinsy
{

/*!
 constructor
 */
TempScore::TempScore()
{}

/*!
 destructor
 */
TempScore::~TempScore()
{
   clear();
}

/*!
 clear
 */
void TempScore::clear()
{
   std::for_each(tempList.begin(), tempList.end(), Deleter<ITempData>());
   tempList.clear();
}

/*!
 write
 */
void TempScore::write(IScoreWritable& sm) const
{
   std::for_each(tempList.begin(), tempList.end(), DataSetter(sm));
}

/*!
 set encoding
 */
void TempScore::setEncoding(const std::string& e)
{
   tempList.push_back(new EncodingSetter(e));
}

/*!
 change tempo
 */
void TempScore::changeTempo(double d)
{
   tempList.push_back(new TempoChanger(d));
}

/*!
 change beat
 */
void TempScore::changeBeat(const Beat& b)
{
   tempList.push_back(new BeatChanger(b));
}

/*!
 change dynamics
 */
void TempScore::changeDynamics(const Dynamics& d)
{
   tempList.push_back(new DynamicsChanger(d));
}

/*!
 change key
 */
void TempScore::changeKey(const Key& k)
{
   tempList.push_back(new KeyChanger(k));
}

/*!
 start crescendo
 */
void TempScore::startCrescendo()
{
   tempList.push_back(new CrescendoStarter());
}

/*!
 start diminuendo
 */
void TempScore::startDiminuendo()
{
   tempList.push_back(new DiminuendoStarter());
}

/*!
 stop crescendo
 */
void TempScore::stopCrescendo()
{
   tempList.push_back(new CrescendoStopper());
}

/*!
 stop diminuendo
 */
void TempScore::stopDiminuendo()
{
   tempList.push_back(new DiminuendoStopper());
}

/*!
 add note
 */
void TempScore::addNote(const Note& n)
{
   tempList.push_back(new NoteAdder(n));
}

/*!
 constructor
 */
TempScore::EncodingSetter::EncodingSetter(const std::string& e) : encoding(e)
{
}

/*!
 destructor
 */
TempScore::EncodingSetter::~EncodingSetter()
{
}

/*!
 write
 */
void TempScore::EncodingSetter::write(IScoreWritable& sm) const
{
   sm.setEncoding(encoding);
}

/*!
 constructor
 */
TempScore::NoteAdder::NoteAdder(const Note& n) : note(n)
{
}

/*!
 destructor
 */
TempScore::NoteAdder::~NoteAdder()
{
}

/*!
 write
 */
void TempScore::NoteAdder::write(IScoreWritable& sm) const
{
   sm.addNote(note);
}

//! get note
const Note& TempScore::NoteAdder::getNote() const
{
   return note;
}

//! get note
Note& TempScore::NoteAdder::getNote()
{
   return note;
}

/*!
 constructor
 */
TempScore::TempoChanger::TempoChanger(double t) : tempo(t)
{
}

/*!
 destructor
 */
TempScore::TempoChanger::~TempoChanger()
{
}

/*!
 write
 */
void TempScore::TempoChanger::write(IScoreWritable& sm) const
{
   sm.changeTempo(tempo);
}

/*!
 constructor
 */
TempScore::BeatChanger::BeatChanger(const Beat& b) : beat(b)
{
}

/*!
 destructor
 */
TempScore::BeatChanger::~BeatChanger()
{
}

/*!
 write
 */
void TempScore::BeatChanger::write(IScoreWritable& sm) const
{
   sm.changeBeat(beat);
}

/*!
 constructor
 */
TempScore::DynamicsChanger::DynamicsChanger(const Dynamics& d) : dynamics(d)
{
}

/*!
 destructor
 */
TempScore::DynamicsChanger::~DynamicsChanger()
{
}

/*!
 write
 */
void TempScore::DynamicsChanger::write(IScoreWritable& sm) const
{
   sm.changeDynamics(dynamics);
}

/*!
 constructor
 */
TempScore::KeyChanger::KeyChanger(const Key& k) : key(k)
{}

/*!
 destructor
 */
TempScore::KeyChanger::~KeyChanger()
{
}

/*!
 write
 */
void TempScore::KeyChanger::write(IScoreWritable& sm) const
{
   sm.changeKey(key);
}

/*!
 constructor
 */
TempScore::CrescendoStarter::CrescendoStarter()
{
}

/*!
 destructor
 */
TempScore::CrescendoStarter::~CrescendoStarter()
{
}

/*!
 write
 */
void TempScore::CrescendoStarter::write(IScoreWritable& sm) const
{
   sm.startCrescendo();
}

/*!
 constructor
 */
TempScore::CrescendoStopper::CrescendoStopper()
{
}

/*!
 destructor
 */
TempScore::CrescendoStopper::~CrescendoStopper()
{
}

/*!
 write
 */
void TempScore::CrescendoStopper::write(IScoreWritable& sm) const
{
   sm.stopCrescendo();
}

/*!
 constructor
 */
TempScore::DiminuendoStarter::DiminuendoStarter()
{
}

/*!
 destructor
 */
TempScore::DiminuendoStarter::~DiminuendoStarter()
{
}

/*!
 write
 */
void TempScore::DiminuendoStarter::write(IScoreWritable& sm) const
{
   sm.startDiminuendo();
}

/*!
 constructor
 */
TempScore::DiminuendoStopper::DiminuendoStopper()
{
}

/*!
 destructor
 */
TempScore::DiminuendoStopper::~DiminuendoStopper()
{
}

/*!
 write
 */
void TempScore::DiminuendoStopper::write(IScoreWritable& sm) const
{
   sm.stopDiminuendo();
}

/*!
 constructor
 */
TempScore::DataSetter::DataSetter(IScoreWritable& sm) : maker(sm)
{
}

/*!
 destructor
 */
TempScore::DataSetter::~DataSetter()
{
}

/*!
 ...
 */
void TempScore::DataSetter::operator()(const ITempData* data)
{
   maker << *data;
}

};  // namespace sinsy
