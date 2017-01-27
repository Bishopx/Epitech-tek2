#include "Teddy.hh"

Teddy::Teddy(obj_type type, std::string const &t) : Toy(type, t) {
	std::cout << "Bonjour je suis un nounours et je m'appelle " << t << std::endl;
}

Teddy::~Teddy() {
	std::cout << "Teddy is dead" << std::endl;
}

Teddy::Teddy(Teddy & other) : Toy(other._type, other._title)
{
	_full = other._full;
	_taken = other._taken;
	_open = other._open;	
}

Teddy &Teddy::operator=(Teddy &other)
{
	_title = other._title;
	_type = other._type;
	_full = other._full;
	_taken = other._taken;
	_open = other._open;
  	return (*this);
}

void	Teddy::isTaken() {
	_taken = true;
	std::cout << "gra hu" << std::endl;
}