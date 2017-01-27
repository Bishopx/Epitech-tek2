#ifndef _BOX_H_
#define _BOX_H_

#include <iostream>
#include <string>
#include "Wrap.hh"

class Box : public Wrap
{
public:
	Box(obj_type);
	virtual ~Box();
  	Box(Box &);
  	Box &operator=(Box &);		
 	virtual void wrapMeThat(Object *);
	virtual void openMe();	
	virtual void closeMe();			
};

#endif /* !_BOX_H_ */