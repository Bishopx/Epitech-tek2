#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "Character.hh"

class  			Warrior : public Character {
private:
	std::string weaponName;	
public:
	Warrior(std::string const &, int);

	int			CloseAttack();
	int			RangeAttack();
};
#endif /* !_WARRIOR_H_ */