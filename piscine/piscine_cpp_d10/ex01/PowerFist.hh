#ifndef _POWERFIST_H_
#define _POWERFIST_H_

#include <iostream>
#include <string>
#include "AWeapon.hh"

class PowerFist : public AWeapon {

public:
	PowerFist();
	virtual void	attack();
};

#endif /* !_POWERFIST_H_ */