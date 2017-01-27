#ifndef _TEDDY_H_
#define _TEDDY_H_

#include <iostream>
#include <string>
#include "Toy.hh"

class Teddy : public Toy
{
public:
	Teddy(obj_type, std::string const &);
	virtual ~Teddy();
  	Teddy(Teddy &);
  	Teddy &operator=(Teddy &);	
	virtual void isTaken(); 
};

#endif /* !_TEDDY_H_ */