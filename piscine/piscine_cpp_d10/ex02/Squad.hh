#ifndef _SQUAD_H_
#define _SQUAD_H_

#include <iostream>
#include <string>
#include <vector>
#include "TacticalMarine.hh"

class ISquad
{
public:
	virtual ~ISquad() {}
	virtual int getCount() const = 0;
	virtual ISpaceMarine* getUnit(int) = 0;
	virtual int push(ISpaceMarine *) = 0;
};

class Squad : public ISquad{
private:
	ISpaceMarine **squad;
	int		_count;
public:
	Squad();
	~Squad() {}
	int getCount() const;
	ISpaceMarine* getUnit(int);
	int push(ISpaceMarine*);	
};
#endif /* !_SQUAD_H_ */