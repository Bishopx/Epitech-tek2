#ifndef _TOY_HH_
#define _TOY_HH_

#include <iostream>
#include <string>
#include "Object.hh"

class Toy : public Object
{
protected:
public:
	Toy();
	virtual ~Toy();
	virtual void isTaken() = 0; 
};

class Teddy : public Toy
{
public:
	Teddy(std::string const &);					
	virtual void isTaken(); 
};

class LittlePony : public Toy
{
public:
	LittlePony(std::string const &);
	virtual void isTaken(); 
};
#endif /* !_TOY_HH_ */