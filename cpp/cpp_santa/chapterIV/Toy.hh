#ifndef _TOY_HH_
#define _TOY_HH_

#include <iostream>
#include <string>
#include "Object.hh"

class Toy : public Object
{
public:
	Toy(obj_type ,std::string const &t);
	virtual ~Toy();
  	Toy(Toy &);
  	Toy &operator=(Toy &);	
	virtual void isTaken() = 0; 
};

#endif /* !_TOY_HH_ */