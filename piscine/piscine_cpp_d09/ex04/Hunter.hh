#ifndef _HUNTER_H_
#define _HUNTER_H_

#include "Character.hh"
#include "Warrior.hh"

class  			Hunter : public Warrior {
protected:
	std::string weaponName;	
public:
	Hunter(std::string const &, int);

	int			CloseAttack();
	int			RangeAttack();
	void		RestorePower();
};
#endif /* !_HUNTER_H_ */