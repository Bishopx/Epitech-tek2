#ifndef CORE_SNAKE_HPP
# define CORE_SNAKE_HPP

# include <unistd.h>
# include <string>
# include <sstream>
# include "IGame.hpp"
# include "Snake.hpp"
# include "Food.hpp"

class CoreSnake : public IGame {
private:
	Snake 	*s;
	Food 	*f;
	IGui 	*g;
	char 	last_dir;
public:
	CoreSnake(IGui *);
	~CoreSnake();
	char PlayGame();
	void setDirection();
	void drawGame();
	void setGui(IGui *);
	int	 getPoint() const;
};

#endif