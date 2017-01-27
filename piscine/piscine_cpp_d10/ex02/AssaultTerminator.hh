#ifndef _ASSAULTTERMINATOR_H_
#define _ASSAULTTERMINATOR_H_

#include <iostream>
#include <string>
#include "TacticalMarine.hh"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	~AssaultTerminator();

	AssaultTerminator & operator=(AssaultTerminator const &);
	virtual AssaultTerminator* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;
};

#endif /* !_ASSAULTTERMINATOR_H_ */