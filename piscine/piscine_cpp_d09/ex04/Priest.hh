#ifndef _PRIEST_H_
#define _PRIEST_H_

#include "Mage.hh"

class  			Priest : public Mage {	
public:
	Priest(std::string const &, int);

	int			CloseAttack();
	int			RangeAttack();
	void		Heal();
};
#endif /* !_PRIEST_H_ */