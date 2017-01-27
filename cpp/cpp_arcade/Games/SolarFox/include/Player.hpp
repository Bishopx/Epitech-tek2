#ifndef PLAYER_H
# define PLAYER_H

# include <iostream>
# include <vector>
# include <cstdlib>
# include "Powerup.hpp"
# include "PlayerBullet.hpp"
# include "Enemy.hpp"

class Player {
	bool 				get;
	int 				width;
	int 				height;
	int 				delay;
	int 				point;
	char 				direction;
	Part 				player, last, bullet, lastBullet, eatPowerUp;
	int 				count;
public:
	Player();
	~Player();
	void 				movePlayer();
	void 				shoot();
	Part const  		&getBullet() const;
	Part const  		&getLastBullet() const;
	Part const  		&getEatPowerUp() const;

	void 				moveBullet();
	void 				addPart();
	void 				restart();
	bool 				collision(Powerup *up, Enemy *enemy);
	void 				setDirection(const char &dir);
	void 				setWidth(int w);
	void 				setHeight(int h);	
	void 				setDelay(int d);		
	const char 			&getDirection() const;
	Part				getPlayer();
	Part 				getLast();
	int 				getDelay();
	int 				getPoint();
	int 				getHeight();
	int 				getPartX();
	int 				getPartY();
};

#endif