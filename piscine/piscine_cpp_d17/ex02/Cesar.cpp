#include "Cesar.h"

void Cesar::encryptChar(char c) {
	int i;

	if (isalpha(c)) {
		for (i = 0; i < _i; i++) {
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

void Cesar::decryptChar(char c) {
	int i = 0;

	if (isalpha(c)) {
		for (i = 0; i < _i; i++) {
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

void Cesar::reset() {
	_i = 3;
}
