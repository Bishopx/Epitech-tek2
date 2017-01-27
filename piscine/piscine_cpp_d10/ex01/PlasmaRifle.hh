#ifndef _PLASMARIFFLE_H_
#define _PLASMARIFFLE_H_

#include <iostream>
#include <string>
#include "AWeapon.hh"

class PlasmaRifle : public AWeapon {

public:
	PlasmaRifle();
	virtual void	attack();
};

#endif /* !_PLASMARIFFLE_H_ */