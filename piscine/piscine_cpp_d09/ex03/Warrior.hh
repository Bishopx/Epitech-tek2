#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "Character.hh"

class  			Warrior : virtual public Character {
protected:
	std::string weaponName;	
public:
	Warrior(std::string const &, int);

	int			CloseAttack();
	int			RangeAttack();
};
#endif /* !_WARRIOR_H_ */