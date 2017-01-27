#ifndef _WOODY_H_
#define _WOODY_H_

#include "Toy.h"


class Woody : public Toy {
public:
	Woody(std::string const &name, std::string const &file = "woody.txt");
	~Woody();
	Woody(Woody const &);
	Woody &operator=(Woody const &);

public:
	virtual bool	speak(std::string const &statement);

};

#endif