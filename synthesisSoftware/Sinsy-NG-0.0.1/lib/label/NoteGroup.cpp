/* Created by Ghost Gloomy on 2018/11/8. */

#include "NoteGroup.h"
#include "util_log.h"

namespace sinsy
{

/*!
 constructor
 */
NoteGroup::NoteGroup() : syllableNum(0)
{
}

/*!
 destructor
 */
NoteGroup::~NoteGroup()
{
}

/*!
 add position
 */
void NoteGroup::addPosition(const LabelPosition& p)
{
   position += p;
}

/*!
 get position
 */
const LabelPosition& NoteGroup::getPosition() const
{
   return position;
}

/*!
 add number of syllables
 */
void NoteGroup::addSyllableNum(size_t n)
{
   syllableNum += n;
}

/*!
 get number of syllables
 */
size_t NoteGroup::getSyllableNum() const
{
   return syllableNum;
}

};  // namespace sinsy
