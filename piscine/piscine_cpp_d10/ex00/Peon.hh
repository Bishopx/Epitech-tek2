#ifndef _PEON_H_
#define _PEON_H_

#include <iostream>
#include <string>
#include "Victim.hh"

class  			Peon : public Victim {
public:
	Peon(std::string const &);
	~Peon();

public:
	void getPolymorphed() const;
};

#endif /* !_PEON_H_ */