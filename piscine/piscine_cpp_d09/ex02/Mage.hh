#ifndef _MAGE_H_
#define _MAGE_H_

#include "Character.hh"

class  			Mage : public Character {	
public:
	Mage(std::string const &, int);

	int			CloseAttack();
	int			RangeAttack();
	void		RestorePower();
};
#endif /* !_MAGE_H_ */