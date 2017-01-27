#ifndef POWERUP_HPP
# define POWERUP_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include "macro.hpp"

struct Part {
	int x,y;
	Part(int col,int row);
	Part();
};

class Powerup {
	std::vector<Part> powerup;

public:
	Powerup();
	~Powerup();
	std::vector<Part> const &getPowerup() const;
	void 					removePowerUp(int);
};

#endif