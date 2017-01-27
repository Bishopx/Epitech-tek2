#ifndef _ONETIME_H_
# define _ONETIME_H_

#include <iostream>
#include <string>
#include "IEncryptionMethod.h"

class OneTime : public IEncryptionMethod
{
private:
	std::string key;
	std::string save;
	unsigned int _i;
public:
 	OneTime(std::string const &k) : key(k), save(k), _i(0) {}
	virtual ~OneTime() {}
	virtual void encryptChar(char plainchar);
	virtual void decryptChar(char cipherchar);
	virtual void reset();
};

#endif
