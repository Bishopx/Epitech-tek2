#include "Buzz.h"

Buzz::Buzz(std::string const &_name, std::string const &file)
	: Toy(BUZZ, _name, file)
{

}

Buzz::~Buzz(){

}

Buzz::Buzz(Buzz const &other) : 
Toy(other.getType(), other.getName(), other.getAscii())
{

}

Buzz &Buzz::operator=(Buzz const &other) {
	this->type = other.type;
	this->name = other.name;
	this->picture = other.picture;

	return *this;
}

bool Buzz::speak(std::string const &statement) {
	std::cout << "BUZZ: " << this->getName() << " \"" << statement << "\"" << std::endl; 
	return true;
}