#ifndef _CESAR_H
# define _CESAR_H

#include <iostream>
#include <string>
#include "IEncryptionMethod.h"

class Cesar : public IEncryptionMethod
{
private:
	int _i;
public:
 	Cesar() : _i(3) {}
	virtual ~Cesar() {}
	virtual void encryptChar(char plainchar);
	virtual void decryptChar(char cipherchar);
	virtual void reset();
};

#endif
