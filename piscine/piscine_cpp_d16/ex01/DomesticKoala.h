#ifndef _DOMESTICKOALA_H_
#define _DOMESTICKOALA_H_

#include <string>
#include <vector>
#include <iostream>

class DomesticKoala {
public:
	 typedef void (KoalaAction::*methodPointer_t)(const std::string &);

private:
	std::vector<methodPointer_t> 	_method;
	std::vector<char> 				_denom;
	KoalaAction 					_koala;
public:
	DomesticKoala(KoalaAction &);
	~DomesticKoala();
	DomesticKoala(DomesticKoala const &);
	DomesticKoala &operator=(DomesticKoala const &);

	 // this type is defined
	 // as a member function pointer.

	 // Retrieves a vector containing all the member function pointers
	 std::vector<methodPointer_t> const * getActions(void) const;

	 // Sets a member function pointer, linking the character (the command) to the pointer (the action).
	 void learnAction(unsigned char, methodPointer_t);

	 // Deletes the command.
	 void unlearnAction(unsigned char);

	 // Executes the action linked to the given command. The string is the parameter given to the member function.
	 void doAction(unsigned char, const std::string&);

	 // Affects a new KoalaAction class to the domestic Koala.
	 // This erases the pointers table.
	 void setKoalaAction(KoalaAction&);
};
#endif