/* Created by Ghost Gloomy on 2018/11/8. */

#include "Note.h"

namespace sinsy
{

/*!
 constructor
 */
Note::Note() : restNote(true), duration(0), breathMark(false), accent(false), staccato(false),
   tieStart(false), tieStop(false), slurStart(false), slurStop(false)
{
}

/*!
 copy constructor
 */
Note::Note(const Note& obj) :
   restNote(obj.restNote), duration(obj.duration), breathMark(obj.breathMark),
   accent(obj.accent), staccato(obj.staccato), tieStart(obj.tieStart), tieStop(obj.tieStop),
   slur(obj.slur), slurStart(obj.slurStart), slurStop(obj.slurStop), pitch(obj.pitch), syllabic(obj.syllabic), lyric(obj.lyric)
{
}

/*!
 destructor
 */
Note::~Note()
{
}

/*!
 set duration
 */
void Note::setDuration(size_t d)
{
   duration = d;
}

/*!
 get duration
 */
size_t Note::getDuration() const
{
   return duration;
}

/*!
 set pitch
 */
void Note::setPitch(const Pitch& p)
{
   pitch = p;
}

/*!
 get pitch
 */
const Pitch& Note::getPitch() const
{
   return pitch;
}

/*!
 set rest
 */
void Note::setRest(bool b)
{
   restNote = b;
}

/*!
 is rest or not
 */
bool Note::isRest() const
{
   return restNote;
}

/*!
 set lyric
 */
void Note::setLyric(const std::string& s)
{
   lyric = s;
}

/*!
 get lyric
 */
const std::string& Note::getLyric() const
{
   return lyric;
}

/*!
 set syllabic
 */
void Note::setSyllabic(const Syllabic& s)
{
   syllabic = s;
}

/*!
 get syllabic
 */
const Syllabic& Note::getSyllabic() const
{
   return syllabic;
}

/*!
 set breath mark
 */
void Note::setBreathMark(bool b)
{
   breathMark = b;
}

/*!
 has breath mark or not
 */
bool Note::hasBreathMark() const
{
   return breathMark;
}

/*!
 set accent
 */
void Note::setAccent(bool b)
{
   accent = b;
}

/*!
 has accent or not
 */
bool Note::hasAccent() const
{
   return accent;
}

/*!
 set staccato
 */
void Note::setStaccato(bool b)
{
   staccato = b;
}

/*!
 has staccato or not
 */
bool Note::hasStaccato() const
{
   return staccato;
}

/*!
 set tie start
 */
void Note::setTieStart(bool b)
{
   tieStart = b;
}

/*!
 is tie start or not
 */
bool Note::isTieStart() const
{
   return tieStart;
}

/*!
 set tie stop
 */
void Note::setTieStop(bool b)
{
   tieStop = b;
}

/*!
 is tie stop or not
 */
bool Note::isTieStop() const
{
   return tieStop;
}

/*!
 get slur
 */
const Slur& Note::getSlur() const
{
   return slur;
}

/*!
 get slur
 */
Slur& Note::getSlur()
{
   return slur;
}

/*!
 set slur start
 */
void Note::setSlurStart(bool b)
{
   slurStart = b;
}

/*!
 is slur start or not
 */
bool Note::isSlurStart() const
{
   return slurStart;
}

/*!
 set slur stop
 */
void Note::setSlurStop(bool b)
{
   slurStop = b;
}

/*!
 is slur stop or not
 */
bool Note::isSlurStop() const
{
   return slurStop;
}

/*!
 to stream
 */
std::ostream& operator<<(std::ostream& os, const Note& note)
{
   if (note.isRest()) {
      os << "[rest(" << note.getDuration() << ") " << note.getLyric();
   } else {
      os << "[pitch(" << note.getDuration() << ") " << note.getPitch() << " " << note.getLyric();
   }

   os << " (tie:";
   if (note.isTieStop()) {
      os << "Stop";
   }
   if (note.isTieStart()) {
      os << "Start";
   }
   os << ")";
   os << " (slur:";
   if (note.isSlurStop()) {
      os << "Stop";
   }
   if (note.isSlurStart()) {
      os << "Start";
   }
   os << ")";
   os << "]";
   return os;
}

};  // namespace sinsy
