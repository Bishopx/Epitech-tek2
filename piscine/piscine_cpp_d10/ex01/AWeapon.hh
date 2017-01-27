#ifndef _AWEAPON_H_
#define _AWEAPON_H_

#include <iostream>
#include <string>

class AWeapon {
private:
	std::string _name;
	int			_apCost;
	int			_damage;
public:
	AWeapon(std::string const & name, int apcost, int damage);
	virtual ~AWeapon();
	std::string const 	&getName() const;
	int 				getAPCost() const;
	int 				getDamage() const;

	virtual void 		attack() = 0;
};

#endif /* !_AWEAPON_H_ */