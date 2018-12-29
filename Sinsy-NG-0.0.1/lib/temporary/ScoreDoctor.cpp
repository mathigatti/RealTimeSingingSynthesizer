/* Created by Ghost Gloomy on 2018/11/8. */

#include <algorithm>
#include "ScoreDoctor.h"
#include "util_log.h"

namespace sinsy
{

namespace
{
const std::string APOSTROPHE_STR = "&apos;";

/*!
 convert apostrophe string to '
 */
void convertApostrophe(Note& note)
{
   std::string lyric(note.getLyric());
   size_t pos = 0;
   bool changed = false;

   while (std::string::npos != (pos = lyric.find(APOSTROPHE_STR, pos))) {
      lyric[pos] = '\'';
      ++pos;
      lyric.erase(pos, APOSTROPHE_STR.size() - 1);
      changed = true;
   }

   if (changed) {
      note.setLyric(lyric);
   }
}

};

/*!
 constructor
 */
ScoreDoctor::ScoreDoctor() : lastTiedNote(NULL), inTie(false)
{
}

/*!
 destructor
 */
ScoreDoctor::~ScoreDoctor()
{
}

/*!
 add note
 */
void ScoreDoctor::addNote(const Note& n)
{
   Note note(n);

   convertApostrophe(note);

   // slur
   if (!note.getSlur().noSlur()) {
      // clear
      note.setSlurStart(false);
      note.setSlurStop(false);

      bool inSlur(!slur.noSlur());
      note.getSlur().mergeTo(slur);
      note.getSlur().clear();
      if (inSlur) {
         if (slur.noSlur()) {
            note.setSlurStop(true);
         }
      } else {
         if (!slur.noSlur()) {
            note.setSlurStart(true);
         }
      }
   }

   // tie
   if (inTie) {
      if (note.isRest() || (lastTiedNote->getNote().getPitch() != note.getPitch())) {
         if (lastTiedNote->getNote().isTieStart()) {
            lastTiedNote->getNote().setTieStart(false);
         } else {
            lastTiedNote->getNote().setTieStop(true);
         }
         inTie = false;
         lastTiedNote = NULL;
      }
   }
   if (note.isTieStop()) {
      inTie = false;
      lastTiedNote = NULL;
   }
   NoteAdder* na = new NoteAdder(note);
   if (note.isTieStart()) {
      inTie = true;
   }
   if (inTie) {
      lastTiedNote = na;
   }

   tempList.push_back(na);
}

};  // namespace sinsy
