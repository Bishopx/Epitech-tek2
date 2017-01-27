#ifndef _LIME_H_
#define _LIME_H_

#include "Fruit.h"

class Lime : public Fruit {

public:
	Lime();
	~Lime();

	std::string const 	&getName() const;
	int 	const		&getVitamins() const;	
};

#endif