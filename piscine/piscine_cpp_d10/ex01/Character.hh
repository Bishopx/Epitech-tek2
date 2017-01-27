#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <string>
#include "AWeapon.hh"
#include "AEnemy.hh"

class Character
{
private:
	std::string const 	_name;
	int					_ap;
	AWeapon 			*_weapon;
public:
	Character(std::string const & name);
	~Character();
	void recoverAP();
	void equip(AWeapon*);
	void attack(AEnemy*);
	std::string const &getName() const;
	int					getAP() const;
	AWeapon 			*getWeapon() const;

	void				setAP(int);
};

std::ostream &operator<<(std::ostream &, Character const &);

#endif /* !_CHARACTER_H_ */