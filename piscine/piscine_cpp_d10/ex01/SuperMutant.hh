#ifndef _SUPERMUTANT_H_
#define _SUPERMUTANT_H_

#include <iostream>
#include <string>
#include "AEnemy.hh"

class SuperMutant : public AEnemy {
public:
	SuperMutant();
	~SuperMutant();

	void takeDamage(int);
};

#endif /* !_SUPERMUTANT_H_ */