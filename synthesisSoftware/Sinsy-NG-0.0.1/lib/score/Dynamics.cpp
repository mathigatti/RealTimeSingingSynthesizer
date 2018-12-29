/* Created by Ghost Gloomy on 2018/11/8. */
#include <algorithm>
#include <stdexcept>
#include "Dynamics.h"
#include "util_log.h"
#include "util_string.h"

namespace sinsy
{

namespace
{
const int DYNAMICS_NUM = 11;

const std::string STR_P4 = "p4";
const std::string STR_P3 = "p3";
const std::string STR_P2 = "p2";
const std::string STR_P1 = "p1";
const std::string STR_MP = "mp";
const std::string STR_N = "n";
const std::string STR_MF = "mf";
const std::string STR_F1 = "f1";
const std::string STR_F2 = "f2";
const std::string STR_F3 = "f3";
const std::string STR_F4 = "f4";
const std::string STR_PPPP = "pppp";
const std::string STR_PPP = "ppp";
const std::string STR_PP = "pp";
const std::string STR_P = "p";
const std::string STR_F = "f";
const std::string STR_FF = "ff";
const std::string STR_FFF = "fff";
const std::string STR_FFFF = "ffff";

const std::string DYNAMICSES[] = {
   STR_P4, STR_P3, STR_P2, STR_P1, STR_MP, STR_N, STR_MF, STR_F1, STR_F2, STR_F3, STR_F4
};
const std::string DYNAMICS_TAGS[] = {
   STR_PPPP, STR_PPP, STR_PP, STR_P, STR_MP, STR_N, STR_MF, STR_F, STR_FF, STR_FFF, STR_FFFF
};

class CompDynamics
{
public:
   //! constructor
   CompDynamics(const std::string& str) : target(str) {}

   //! destructor
   virtual ~CompDynamics() {}

   //! ...
   bool operator()(const std::string& str) const {
      return (0 == target.compare(str)) ? true : false;
   }

   //! target
   const std::string& target;
};

};

const Dynamics Dynamics::PPPP(STR_PPPP);
const Dynamics Dynamics::PPP(STR_PPP);
const Dynamics Dynamics::PP(STR_PP);
const Dynamics Dynamics::P(STR_P);
const Dynamics Dynamics::MP(STR_MP);
const Dynamics Dynamics::N(STR_N);
const Dynamics Dynamics::MF(STR_MF);
const Dynamics Dynamics::F(STR_F);
const Dynamics Dynamics::FF(STR_FF);
const Dynamics Dynamics::FFF(STR_FFF);
const Dynamics Dynamics::FFFF(STR_FFFF);

/*!
 constructor
 */
Dynamics::Dynamics() : value((DYNAMICS_NUM - 1) / 2)
{
}

/*!
 constructor
 */
Dynamics::Dynamics(const std::string& str)
{
   set(str);
}

/*!
 copy constructor
 */
Dynamics::Dynamics(const Dynamics& obj) : value(obj.value)
{
}

/*!
 destructor
 */
Dynamics::~Dynamics()
{
}

/*!
 assignment operator
 */
Dynamics& Dynamics::operator=(const Dynamics & obj)
{
   value = obj.value;
   return *this;
}

/*!
 equal
 */
bool Dynamics::operator==(const Dynamics& obj) const
{
   return (obj.value == value);
}

/*!
 not equal
 */
bool Dynamics::operator!=(const Dynamics& obj) const
{
   return !(obj == *this);
}

/*!
 set value
 */
void Dynamics::set(const std::string& _str)
{
   std::string s(_str);
   toLower(s);
   const std::string* itr(std::find_if(DYNAMICSES, DYNAMICSES + DYNAMICS_NUM, CompDynamics(s)));
   if (itr < DYNAMICSES + DYNAMICS_NUM) {
      value = itr - DYNAMICSES;
      return;
   }
   itr = std::find_if(DYNAMICS_TAGS, DYNAMICS_TAGS + DYNAMICS_NUM, CompDynamics(s));
   if (itr < DYNAMICS_TAGS + DYNAMICS_NUM) {
      value = itr - DYNAMICS_TAGS;
      return;
   }
   ERR_MSG("Unexpected dynamics : " << s);
   throw std::runtime_error("Dynamics::set() invalid argument");
}

/*!
 get valie as string
 */
const std::string& Dynamics::getStr() const
{
   return DYNAMICSES[value];
}

/*!
 get tag string
 */
const std::string& Dynamics::getTagStr() const
{
   return DYNAMICS_TAGS[value];
}

/*!
 to string
 */
std::ostream& operator<<(std::ostream& os, const Dynamics& dynamics)
{
   return os << dynamics.getStr();
}

};  // namespace sinsy
