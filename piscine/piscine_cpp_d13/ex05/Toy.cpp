#include "Toy.h"

Toy::Toy() :
	type(BASIC_TOY), name("toy"), picture(Picture()), error(Error::UNKNOWN)
{

}

Toy::Toy(ToyType const &_type,std::string const &_name, std::string const &file) : 
	type(_type), name(_name), picture(Picture(file)), error(Error::UNKNOWN)
{

}

Toy::~Toy(){

}

Toy::Toy(Toy const &other) : 
type(other.type), name(other.name), 
picture(other.picture), error(other.error)
{

}

Toy &Toy::operator=(Toy const &other) {
	this->type = other.type;
	this->name = other.name;
	this->picture = other.picture;
	this->error = other.error;

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
	bool test;

	test = picture.getPictureFromFile(file);
	if (test == false)
		error = Error::PICTURE;
	return test;
}

void Toy::speak(std::string const &statement) {
	std::cout << name << " \"" << statement << "\"" << std::endl; 
}

bool Toy::speak_es(std::string const &statement) {
	if (this->getType() == BUZZ) {
		std::cout << "BUZZ: " << this->getName() << " senorita \"" << statement << "\" senorita" << std::endl; 
		return true;
	} else {
		error = Error::SPEAK;		
		return false;
	}
}

Toy::Error Toy::getLastError() const {
	Toy::Error e;

	e.type = error;
	return e;
}

void Toy::operator<<(std::string const &a) {
	this->picture.data = a;
}

std::ostream &operator<<(std::ostream &os, Toy const &toy) {
	os << toy.getName() << std::endl << toy.getAscii() << std::endl;
	return os;
}

std::string  Toy::Error::what() const {
	if (type == Error::PICTURE)
		return "bad new illustration";
	if (type == Error::SPEAK)
		return "wrong mode";
	return "";
}

std::string  Toy::Error::where() const {
	if (type == Error::SPEAK)
		return "speak_es";
	if (type == Error::PICTURE)
		return "setAscii";
	return "";
}