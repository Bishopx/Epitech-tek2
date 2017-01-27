#ifndef _PALADIN_H_
#define _PALADIN_H_

#include "Warrior.hh"
#include "Priest.hh"

class  			Paladin : public Warrior, public Priest {
public:
	Paladin(std::string const &, int);
	int CloseAttack();
	int RangeAttack();
	int Intercept();
};

#endif /* !_PALADIN_H_ */