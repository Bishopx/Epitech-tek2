#include "Toy.h"

Toy::Toy() :
	type(BASIC_TOY), name("toy"), picture(Picture())
{

}

Toy::Toy(ToyType const &_type,std::string const &_name, std::string const &file) : 
	type(_type), name(_name), picture(Picture(file))
{

}

Toy::~Toy(){

}

Toy::Toy(Toy const &other) : 
type(other.type), name(other.name), picture(other.picture)
{

}

Toy &Toy::operator=(Toy const &other) {
	this->type = other.type;
	this->name = other.name;
	this->picture = other.picture;

	return *this;
}

Toy::ToyType const &Toy::getType() const {
	return type;
}

std::string const &Toy::getName() const {
	return name;
}

std::string const &Toy::getAscii() const {
	return picture.data;
}

void Toy::setName(std::string const &_name) {
	name = _name;
}

bool Toy::setAscii(std::string const &file) {
	return picture.getPictureFromFile(file);
}

void Toy::speak(std::string const &statement) {
	std::cout << name << " \"" << statement << "\"" << std::endl; 
}