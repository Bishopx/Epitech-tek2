#include "Character.hh"

Character::Character(std::string const &name) : _name(name), _ap(40) {
}

Character::~Character() {}

std::string	const	&Character::getName() const {
	return (_name);
}

int 				Character::getAP() const {
	return _ap;
}

AWeapon 			*Character::getWeapon() const {
	return _weapon;
}

void 				Character::setAP(int ap) {
	_ap -= ap;
}

void	Character::recoverAP() {
	if (_ap <= 30)
		_ap += 10;
	else
		_ap = 40;
}

void 	Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

void	Character::attack(AEnemy *enemy) {
	if (this->getWeapon()) {
		this->setAP(this->_weapon->getAPCost());
		std::cout << _name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;				
		this->_weapon->attack();
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
	}
}

std::ostream &operator<<(std::ostream &os, Character const &c) {
	if (c.getWeapon())
		os << c.getName() << " has " << c.getAP() << " AP and wields a " << c.getWeapon()->getName() << std::endl;
	else
		os << c.getName() << " has " << c.getAP() << " AP and is unarmed" << std::endl;		
	return os;
}