#include "Woody.h"
#include "Buzz.h"

Woody::Woody(std::string const &_name, std::string const &file) 
	: Toy(WOODY, _name, file)
{

}

Woody::~Woody(){

}

Woody::Woody(Woody const &other) : 
Toy(other.getType(), other.getName(), other.getAscii())
{

}

Woody &Woody::operator=(Woody const &other) {
	this->type = other.type;
	this->name = other.name;
	this->picture = other.picture;

	return *this;
}

void Woody::speak(std::string const &statement) {
	std::cout << "WOODY: " << this->getName() << " \"" << statement << "\"" << std::endl; 
}