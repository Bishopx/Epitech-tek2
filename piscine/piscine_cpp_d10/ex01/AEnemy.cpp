#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const &type) : _hp(hp), _type(type) {}

AEnemy::~AEnemy() {}

std::string const &AEnemy::getType() const {
	return (_type);
}

int		AEnemy::getHP() const {
	return (_hp);
}

void	AEnemy::takeDamage(int damage) {
	if (damage > 0)
		_hp -= damage;
}

void	AEnemy::setHP(int hp) {
	_hp = hp;
}