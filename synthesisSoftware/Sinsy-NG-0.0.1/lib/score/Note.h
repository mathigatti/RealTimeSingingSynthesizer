/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_NOTE_H_
#define SINSY_NOTE_H_

#include <string>
#include "Pitch.h"
#include "Syllabic.h"
#include "Slur.h"

namespace sinsy
{

class Note
{
public:
   //! constructor
   Note();

   //! copy constructor (donot use)
   Note(const Note& obj);

   //! destructor
   virtual ~Note();

   //! set duration
   void setDuration(size_t d);

   //! get duration
   size_t getDuration() const;

   //! set pitch
   void setPitch(const Pitch& p);

   //! get pitch
   const Pitch& getPitch() const;

   //! set rest
   void setRest(bool f);

   //! is rest or not
   bool isRest() const;

   //! set lyric
   void setLyric(const std::string& s);

   //! get lyric
   const std::string& getLyric() const;

   //! set syllabic
   void setSyllabic(const Syllabic& s);

   //! get syllabic
   const Syllabic& getSyllabic() const;

   //! set breath mark
   void setBreathMark(bool f);

   //! has breath mark or not
   bool hasBreathMark() const;

   //! set accent
   void setAccent(bool f);

   //! has accent or not
   bool hasAccent() const;

   //! set staccato
   void setStaccato(bool f);

   //! has staccato or not
   bool hasStaccato() const;

   //! set tie start
   void setTieStart(bool f);

   //! is tie start or not
   bool isTieStart() const;

   //! set tie stop
   void setTieStop(bool f);

   //! is tie stop or not
   bool isTieStop() const;

   //! get slur
   const Slur& getSlur() const;

   //! get slur
   Slur& getSlur();

   //! set slur start
   void setSlurStart(bool f);

   //! is slur start or not
   bool isSlurStart() const;

   //! set slur stop
   void setSlurStop(bool f);

   //! is slur stop or not
   bool isSlurStop() const;

private:
   //! assignment operator (donot use)
   Note& operator=(const Note&);

   //! is rest note or not
   bool restNote;

   //! duration
   size_t duration;

   //! has breath mark or not
   bool breathMark;

   //! has accent or not
   bool accent;

   //! has staccato or not
   bool staccato;

   //! is tie start or not
   bool tieStart;

   //! is tie stop or not
   bool tieStop;

   //! slur
   Slur slur;

   //! is slur start or not
   bool slurStart;

   //! is slur stop or not
   bool slurStop;

   //! pitch
   Pitch pitch;

   //! syllabic
   Syllabic syllabic;

   //! lyric
   std::string lyric;
};

//! to stream
std::ostream& operator<<(std::ostream&, const Note&);
};

#endif // SINSY_NOTE_H_
