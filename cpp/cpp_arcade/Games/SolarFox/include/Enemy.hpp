#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <vector>
# include "Powerup.hpp"

struct EPart {
	int x,y;
	char dir;
	EPart(int col,int row, char d);
	EPart();
};

class Enemy {
	std::vector<EPart> 	enemy, bullet;
	std::vector<Part> 	last, lastBullet;

public:
	Enemy();
	~Enemy();
	std::vector<EPart> const 	&getEnemy() const;
	std::vector<Part> const 	&getEnemyLast() const;
	std::vector<Part> const 	&getEnemyLastBullet() const;		
	std::vector<EPart> const 	&getEnemyBullet() const;	
	void 						move();
	void 						moveShoot();
	void 						shoot(Part);
};

#endif 