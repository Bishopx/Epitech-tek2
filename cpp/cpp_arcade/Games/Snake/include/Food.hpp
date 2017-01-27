#ifndef FOOD_HPP
# define FOOD_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include "macro.hpp"

struct Part {
	int x,y;
	Part(int col,int row);
	Part();
};

class Food {
	Part food;

public:
	Food();
	~Food();
	void putFood();
	Part const &getFood() const;
};

#endif