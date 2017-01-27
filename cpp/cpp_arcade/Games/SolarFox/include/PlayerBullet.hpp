#ifndef PLAYERBULLET_HPP
# define PLAYERBULLET_HPP

#include "Powerup.hpp"


class PlayerBullet {
	char 	dir;
	Part 	bullet;
	Part 	lastBullet;
public:
	PlayerBullet(char, int, int);
	~PlayerBullet();

	Part const 	&getBullet() const;
	Part const 	&getLastBullet() const;
	void 		move();
};

#endif