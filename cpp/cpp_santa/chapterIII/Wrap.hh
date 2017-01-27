#ifndef _WRAP_H_
#define _WRAP_H_

#include <iostream>
#include <string>
#include "Object.hh"

class Wrap : public Object
{
public:
	Wrap(obj_type);
	virtual ~Wrap();
  	Wrap(Wrap &);
  	Wrap &operator=(Wrap &);		
	virtual void isTaken();
	virtual void openMe() {}
};

#endif /* !_WRAP_H_ */