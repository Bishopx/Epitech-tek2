#ifndef _BUZZ_H_
#define _BUZZ_H_

#include "Toy.h"

class Buzz : public Toy {
public:
	Buzz(std::string const &name, std::string const &file = "buzz.txt");
	~Buzz();
	Buzz(Buzz const &);
	Buzz &operator=(Buzz const &);

public:
	virtual void 	speak(std::string const &statement);
};
#endif