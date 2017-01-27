#include "OneTime.h"
#include <bitset>

void OneTime::encryptChar(char c) {
	int i = 0;
	char save;

	if (_i == key.size())
		_i = 0;
	if (key[_i] >= 'a' && key[_i] <= 'z')
		save = 'a';
	if (key[_i] >= 'A' && key[_i] <= 'Z')
		save = 'A';
	while (save != key[_i]) {
		i++;
		save++;
	}
	if (isalpha(c)) {
		for (int j = 0; j < i; j++) {
			if (c == 'z')
				c = 'a';
			else if (c == 'Z')
				c = 'A';
			else
				c++;
		}
	}	
	_i++;
	std::cout << c;
}

void OneTime::decryptChar(char c) {
	int i = 0;
	char save;

	if (_i == key.size())
		_i = 0;
	if (key[_i] >= 'a' && key[_i] <= 'z')
		save = 'a';
	if (key[_i] >= 'A' && key[_i] <= 'Z')
		save = 'A';
	while (save != key[_i]) {
		i++;
		save++;
	}
	if (isalpha(c)) {
		for (int j = 0; j < i; j++) {
			if (c == 'a')
				c = 'z';
			else if (c == 'A')
				c = 'Z';
			else
				c--;
		}
	}	
	_i++;
	std::cout << c;
}

void OneTime::reset() {
	_i = 0;
}
