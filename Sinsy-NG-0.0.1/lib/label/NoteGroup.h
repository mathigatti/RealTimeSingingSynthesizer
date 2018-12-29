/* Created by Ghost Gloomy on 2018/11/8. */

#ifndef SINSY_NOTE_GROUP_H_
#define SINSY_NOTE_GROUP_H_

#include "util_types.h"
#include "LabelPosition.h"

namespace sinsy
{

class NoteGroup
{
public:
   //! constructor
   NoteGroup();

   //! destructor
   virtual ~NoteGroup();

   //! add position
   void addPosition(const LabelPosition& p);

   //! get position
   const LabelPosition& getPosition() const;

   //! add number of syllables
   void addSyllableNum(size_t n);

   //! get number of syllables
   size_t getSyllableNum() const;

private:
   //! copy constructor (donot use)
   NoteGroup(const NoteGroup&);

   //! assignment operator (donot use)
   NoteGroup& operator=(const NoteGroup&);

   //! position
   LabelPosition position;

   //! number of syllables
   size_t syllableNum;
};

};

#endif // SINSY_NOTE_GROUP_H_
