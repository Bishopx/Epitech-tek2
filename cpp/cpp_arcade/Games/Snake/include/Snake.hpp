#ifndef SNAKE_H
# define SNAKE_H

# include <iostream>
# include <vector>
# include <cstdlib>
# include "Food.hpp"

class Snake {
	bool 				get;
	int 				width;
	int 				height;
	int 				delay;
	int 				point;
	char 				direction;
	std::vector<Part> 	snake;
	Part 				last;

public:
	Snake();
	~Snake();
	void 				moveSnake();
	void 				addPart();
	void 				restart();
	bool 				collision(Food *food);
	void 				setDirection(const char &dir);
	void 				setWidth(int w);
	void 				setHeight(int h);	
	void 				setDelay(int d);		
	const char 			&getDirection() const;
	std::vector<Part> 	getSnake();
	Part 				getLast();
	int 				getDelay();
	int 				getPoint();
	int 				getHeight();
};

#endif