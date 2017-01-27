#ifndef _RATATOUILLE_H_
#define _RATATOUILLE_H_

#include <sstream>
#include <string>
#include <iostream>

class Ratatouille {
public:
	std::ostringstream oss;

public:
	Ratatouille();
	 Ratatouille(Ratatouille const &);
	 ~Ratatouille();
	 Ratatouille &operator=(const Ratatouille &);

	 Ratatouille &addVegetable(unsigned char);
	 Ratatouille &addCondiment(unsigned int);
	 Ratatouille &addSpice(double);
	 Ratatouille &addSauce(const std::string &);

	 std::string kooc(void);	
};

#endif