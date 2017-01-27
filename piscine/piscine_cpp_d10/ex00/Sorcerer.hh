#ifndef _SORCERER_H_
#define _SORCERER_H_

#include <iostream>
#include <string>
#include "Victim.hh"

class  			Sorcerer {
protected:
	std::string _name;
	std::string _title;
public:
	Sorcerer(std::string const &, std::string const &);
	~Sorcerer();

public:
	std::string const &getName() const;
	std::string const &getTitle() const;
	void		polymorph(Victim const &) const;
};

std::ostream	&operator<<(std::ostream &, Sorcerer const &);

#endif /* !_SORCERER_H_ */