#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <string>

class 		Character {
protected:
	std::string		name;
	int				level;
	int				pv;
	int				power;
	int				Strength;
	int				Stamina;
	int				Agility;
	int				Intelligence;
	int 			Spirit;

public:
	enum AttackRange {
			CLOSE,
			RANGE
	};
	AttackRange		Range;

public:
	Character(std::string const &, int);

	const std::string 		&getName() const;
	int				const 	&getLvl() const;
	int				const 	&getPv() const;
	int				const 	&getPower() const;

	int						CloseAttack();
	int						RangeAttack();
	void					Heal();
	void					RestorePower();
	void					TakeDamage(int);
};
#endif /* !_CHARACTER_H_ */