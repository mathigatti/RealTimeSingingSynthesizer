/* Created by Ghost Gloomy on 2018/11/8. */
#ifndef SINSY_DYNAMICS_H_
#define SINSY_DYNAMICS_H_

#include <string>

namespace sinsy
{

class Dynamics
{
public:
   static const Dynamics PPPP;
   static const Dynamics PPP;
   static const Dynamics PP;
   static const Dynamics P;
   static const Dynamics MP;
   static const Dynamics N;
   static const Dynamics MF;
   static const Dynamics F;
   static const Dynamics FF;
   static const Dynamics FFF;
   static const Dynamics FFFF;

   //! constructor
   Dynamics();

   //! constructor
   explicit Dynamics(const std::string& str);

   //! copy constructor
   Dynamics(const Dynamics& obj);

   //! destructor
   virtual ~Dynamics();

   //! assignment operator
   Dynamics& operator=(const Dynamics& obj);

   //! equal
   bool operator==(const Dynamics& obj) const;

   //! not equal
   bool operator!=(const Dynamics& obj) const;

   //! set value
   void set(const std::string& str);

   //! get value as string
   const std::string& getStr() const;

   //! get tag string
   const std::string& getTagStr() const;

private:
   //! value
   size_t value;
};

//! to string
std::ostream& operator<<(std::ostream& os, const Dynamics& dynamics);
};

#endif // SINSY_DYNAMICS_H_
