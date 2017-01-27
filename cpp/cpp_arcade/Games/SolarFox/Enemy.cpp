#include "Enemy.hpp"

EPart::EPart(int col,int row, char d)
{
	x=col;
	y=row;
	dir = d;
}

EPart::EPart()
{
	x=0;
	y=0;
	dir = 'n';
}

Enemy::Enemy(){
	enemy.push_back(EPart(20, 0, 'r'));
	last.push_back(Part(20, 0));
	enemy.push_back(EPart(0, 20, 'd'));
	last.push_back(Part(0, 20));
	enemy.push_back(EPart(20, 39, 'l'));
	last.push_back(Part(20, 39));
	enemy.push_back(EPart(41, 20, 'u'));
	last.push_back(Part(41, 20));
}

Enemy::~Enemy(){
}

std::vector<EPart> const		&Enemy::getEnemy() const{
	return enemy;
}

std::vector<Part> const		&Enemy::getEnemyLast() const{
	return last;
}

std::vector<EPart> const		&Enemy::getEnemyBullet() const{
	return bullet;
}

std::vector<Part> const		&Enemy::getEnemyLastBullet() const{
	return lastBullet;
}

void 						Enemy::shoot(Part player){
	for (unsigned int i = 0; i < enemy.size(); i++){
		if (enemy[i].x == 0 && player.y == enemy[i].y){
				bullet.push_back(EPart(enemy[i].x, enemy[i].y, 'd'));
				lastBullet.push_back(Part(enemy[i].x, enemy[i].y));					
		}
		else if (enemy[i].x == 41 && player.y == enemy[i].y){
				bullet.push_back(EPart(enemy[i].x, enemy[i].y, 'u'));
				lastBullet.push_back(Part(enemy[i].x, enemy[i].y));					
		}
		else if (enemy[i].y == 0 && player.x == enemy[i].x){
				bullet.push_back(EPart(enemy[i].x, enemy[i].y, 'r'));
				lastBullet.push_back(Part(enemy[i].x, enemy[i].y));					
		}
		else if (enemy[i].y == 39 && player.x == enemy[i].x){
				bullet.push_back(EPart(enemy[i].x, enemy[i].y, 'l'));
				lastBullet.push_back(Part(enemy[i].x, enemy[i].y));					
		}
	}
}

void 						Enemy::moveShoot(){
	for (unsigned int i = 0; i < bullet.size(); i++){
		if (bullet[i].dir == 'd'){
			if (bullet[i].y == 39){
				bullet.erase(bullet.begin() + i);
				lastBullet.erase(lastBullet.begin() + i);
			}
			else{
				lastBullet[i].x = bullet[i].x;
				bullet[i].x += 1;
			}
		}
		else if (bullet[i].dir == 'u'){
			if (bullet[i].y == 0){
				bullet.erase(bullet.begin() + i);
				lastBullet.erase(lastBullet.begin() + i);
			}
			else{
				lastBullet[i].x = bullet[i].x;
				bullet[i].x -= 1;
			}
		}
		else if (bullet[i].dir == 'r'){
			if (bullet[i].x == 39){
				bullet.erase(bullet.begin() + i);
				lastBullet.erase(lastBullet.begin() + i);
			}
			else{
				lastBullet[i].y = bullet[i].y;
				bullet[i].y += 1;
			}
		}
		else if (bullet[i].dir == 'l'){
			if (bullet[i].x == 0){
				bullet.erase(bullet.begin() + i);
				lastBullet.erase(lastBullet.begin() + i);
			}
			else{
				lastBullet[i].y = bullet[i].y;
				bullet[i].y -= 1;
			}
		}
	}
}

void 						Enemy::move(){
	for (unsigned int i = 0; i < enemy.size(); i++){
		if (enemy[i].dir == 'r'){
			if (enemy[i].x == 40)
				enemy[i].dir = 'l';
			else{
				last[i].x = enemy[i].x;
				enemy[i].x++;
			}
		}
		else if (enemy[i].dir == 'l'){
			if (enemy[i].x == 1)
				enemy[i].dir = 'r';
			else{
				last[i].x = enemy[i].x;
				enemy[i].x--;
			}
		}
		else if (enemy[i].dir == 'u'){
			if (enemy[i].y == 1)
				enemy[i].dir = 'd';
			else{
				last[i].y = enemy[i].y;
				enemy[i].y--;
			}
		}
		else if (enemy[i].dir == 'd'){
			if (enemy[i].y == 38)
				enemy[i].dir = 'u';
			else{
				last[i].y = enemy[i].y;
				enemy[i].y++;
			}
		}
	}
}