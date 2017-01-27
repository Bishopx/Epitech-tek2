#ifndef _VICTIM_H
#define _VICTIM_H

#include <iostream>
#include <string>

class  			Victim {
protected:
	std::string _name;
public:
	Victim(std::string const &);
	~Victim();

public:
	std::string const &getName() const;

	virtual void getPolymorphed() const;
};

std::ostream	&operator<<(std::ostream &, Victim const &);

#endif /* !_VICTIM_H */