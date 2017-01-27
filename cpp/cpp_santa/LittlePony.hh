#ifndef _LITTLEPONY_H_
#define _LITTLEPONY_H_

#include <iostream>
#include <string>
#include "Toy.hh"

class LittlePony : public Toy
{
public:
	LittlePony(obj_type, std::string const &);
	virtual ~LittlePony();
  	LittlePony(LittlePony &);
  	LittlePony &operator=(LittlePony &);		
	virtual void isTaken(); 
};

#endif /* !_LITTLEPONY_H_ */