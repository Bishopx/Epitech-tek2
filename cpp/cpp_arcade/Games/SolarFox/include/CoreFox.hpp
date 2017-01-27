#ifndef CORE_FOX_
# define CORE_FOX_

# include <unistd.h>
# include <string>
# include <sstream>
# include "IGame.hpp"
# include "Player.hpp"
# include "PlayerBullet.hpp"
# include "Powerup.hpp"
# include "Enemy.hpp"

class CoreFox : public IGame {
private:
	Player 			*player;
	Enemy 			*enemy;
	Powerup 		*up;
	IGui 			*gui;
	char 	last_dir;
public:
	CoreFox(IGui *);
	~CoreFox();
	char PlayGame();
	void setDirection();
	void drawGame();
	void setGui(IGui *);
	int getPoint() const;
};

#endif