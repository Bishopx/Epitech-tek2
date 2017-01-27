#ifndef _AENEMY_H_
#define _AENEMY_H_

#include <iostream>
#include <string>

class AEnemy
{
private:
	int	_hp;
	std::string const _type;
public:
	AEnemy(int hp, std::string const & type);
	virtual ~AEnemy();

	std::string const &getType() const;
	int getHP() const;
	virtual void takeDamage(int);
	void setHP(int);
};

#endif /* !_AENEMY_H_ */