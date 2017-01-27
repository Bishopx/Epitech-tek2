#include "DomesticKoala.h"

DomesticKoala::DomesticKoala(KoalaAction &action) {
	_koala = action;
}

DomesticKoala::~DomesticKoala() {

}

DomesticKoala::DomesticKoala(DomesticKoala const &other) {
	_method = other._method;
	_denom = other._denom;
}

DomesticKoala &DomesticKoala::operator=(DomesticKoala const &other) {
	_method = other._method;
	_denom = other._denom;
	return *this;
}

std::vector<DomesticKoala::methodPointer_t> const *DomesticKoala::getActions() const {
	return &_method;
}

void DomesticKoala::learnAction(unsigned char c, methodPointer_t method) {
	_denom.push_back(c);
	_method.push_back(method); 
}

void DomesticKoala::unlearnAction(unsigned char c) {
	unsigned int i = 0;

	while (_denom[i] != c && i < _denom.size())
		i++;
	if (i < _denom.size()) {
		_denom.erase(_denom.begin() + i);
		_method.erase(_method.begin() + i);	
	}
}

void DomesticKoala::setKoalaAction(KoalaAction &other) {
	_koala = other;
	_denom.erase(_denom.begin(), _denom.begin() + _denom.size());
	_method.erase(_method.begin(), _method.begin() + _method.size());
}

void DomesticKoala::doAction(unsigned char c, const std::string &str) {
	unsigned int i = 0;

	while (_denom[i] != c && i < _denom.size())
		i++;
	if (i < _denom.size()) {
		(this->_koala.*_method[i])(str);
	}
}