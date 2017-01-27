#ifndef _FRUIT_H_
#define _FRUIT_H_

#include <iostream>
#include <string>

class Fruit {
protected:
	int 		_vitamins;
	std::string _name;
public:
	Fruit(int, std::string const &);
	virtual ~Fruit();

	virtual int 		const	&getVitamins() const = 0;
	virtual std::string const 	&getName() const = 0;
};

#endif