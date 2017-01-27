#ifndef _BANANA_H_
#define _BANANA_H_

#include "Fruit.h"

class Banana : public Fruit {

public:
	Banana();
	~Banana();

	std::string const 	&getName() const;
	int 	const		&getVitamins() const;	
};

#endif