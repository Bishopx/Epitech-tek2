
#include <iostream>
#include <string>
#include "Sorcerer.hh"

Sorcerer::Sorcerer(std::string const &Name, std::string const &Title) : 
_name(Name), _title(Title){
	std::cout << Name << ", " << Title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer() {
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string const &Sorcerer::getName() const{
	return (_name);
}

std::string const &Sorcerer::getTitle() const{
	return (_title);
}

void		Sorcerer::polymorph(Victim const &v) const {
	v.getPolymorphed();
}

std::ostream &operator<<(std::ostream &os, Sorcerer const &s) {
	os << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies !" << std::endl;
	return (os);
}
