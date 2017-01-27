#ifndef _ENCRYPTION_H_
# define _ENCRYPTION_H_

#include <iostream>
#include <string>
#include "IEncryptionMethod.h"

class Encryption
{
public:
	typedef void (IEncryptionMethod::*func_t)(const char &c);
private:
	IEncryptionMethod  	*_enc;
	void (IEncryptionMethod::*_func)(char);
public:
	Encryption(IEncryptionMethod &, void (IEncryptionMethod::*)(char));
	Encryption &operator()(char c);
};

#endif
