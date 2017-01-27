#include "Encryption.h"

Encryption::Encryption(IEncryptionMethod &enc, void (IEncryptionMethod::*func)(char c)) {
	this->_enc = &enc;
	this->_func = func;
}

Encryption &Encryption::operator()(char c) {
	(this->_enc->*_func)(c);
}
