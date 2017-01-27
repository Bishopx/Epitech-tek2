/* Droid Memory */
#include <cstdlib>
#include <ostream>
#include "droidmemory.hh"

DroidMemory::DroidMemory(){
	this->Exp = 0;
	this->FingerPrint = (size_t) random();
}

DroidMemory::DroidMemory(DroidMemory const &other) : FingerPrint(other.FingerPrint), Exp(other.Exp){
}

DroidMemory &DroidMemory::operator=(DroidMemory const &other) {
	if (&other != this) {
		this->Exp = other.Exp;
		this->FingerPrint = other.FingerPrint;
	}
	return (*this);
}

DroidMemory::~DroidMemory() {

}

size_t const &DroidMemory::getFingerPrint() const {
	return FingerPrint;
}

size_t const &DroidMemory::getExp() const {
	return Exp;
}

void	DroidMemory::setFingerPrint(size_t finger) {
	this->FingerPrint = finger;
}

void	DroidMemory::setExp(size_t exp) {
	this->Exp = exp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory const &d) {
	this->Exp += d.getExp();
	this->FingerPrint = d.getFingerPrint() ^ this->FingerPrint;
	return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &d) {
	d.setExp(this->Exp + d.getExp()); 
	d.setFingerPrint(this->FingerPrint ^ d.getFingerPrint());
	return d;
}

DroidMemory &DroidMemory::operator+=(DroidMemory const &d) {
	this->Exp += d.getExp();
	this->FingerPrint = d.getFingerPrint() ^ this->FingerPrint;
	return *this;
}

DroidMemory &DroidMemory::operator+=(size_t const &exp) {
	this->Exp += exp;
	this->FingerPrint = exp ^ this->FingerPrint;
	return *this;
}


DroidMemory &DroidMemory::operator+(DroidMemory const &d) {
	DroidMemory *p = new DroidMemory();
	p->Exp = this->Exp + d.getExp();
	p->FingerPrint = this->FingerPrint ^ d.getFingerPrint();
	return *p;
}

DroidMemory &DroidMemory::operator+(size_t const &d) {
	DroidMemory *p = new DroidMemory();
	p->Exp = this->Exp + d;
	p->FingerPrint = this->FingerPrint ^ d;
	return *p;
}

std::ostream &operator<<(std::ostream &os, DroidMemory const &memory) {
	os << "DroidMemory '" << memory.getFingerPrint() << "', " << memory.getExp();
	return (os);
}

