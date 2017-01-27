#ifndef _LEMON_H_
#define _LEMON_H_

#include "Fruit.h"

class Lemon : public Fruit {

public:
	Lemon();
	~Lemon();

	std::string const &getName() const;
	int 	const		&getVitamins() const;

};

#endif