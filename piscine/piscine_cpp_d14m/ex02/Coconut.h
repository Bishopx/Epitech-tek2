#ifndef _COCONUT_H_
#define _COCONUT_H_

#include "Fruit.h"

class Coconut : public Fruit {

public:
	Coconut();
	~Coconut();

	std::string const 	&getName() const;
	int 	const		&getVitamins() const;	
};

#endif