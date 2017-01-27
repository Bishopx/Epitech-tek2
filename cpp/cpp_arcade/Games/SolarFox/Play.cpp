#include "Player.hpp"
#include "PlayerBullet.hpp"
#include "Enemy.hpp"
#include "Powerup.hpp"
#include "Protocol.hpp"
#include <unistd.h>

void setDirection(Player *player, arcade::CommandType com) {
	if (com == arcade::CommandType::GO_UP)
		player->setDirection('u');
	if (com == arcade::CommandType::GO_DOWN)
		player->setDirection('d');
	if (com == arcade::CommandType::GO_LEFT)
		player->setDirection('l');
	if (com == arcade::CommandType::GO_RIGHT)
		player->setDirection('r');
	if (com == arcade::CommandType::SHOOT)
		player->setDirection('s');			
}

void initMap(arcade::GetMap *map, Player *player, arcade::CommandType buff) {
	int x;
	int y;

	player = player;
	map->type = buff;
	map->width = 40;
	map->height = 40;
	for (int i = 0; i < 40 * 40; i++) {
		x = i % 40;
		y = y / 40;
		x = x;
		y = y;
		if (x == 0 || x == 39 || y == 0 || y == 39)
			map->tile[i] = arcade::TileType::BLOCK_TILE;							
		else if (x == player->getBullet().x && y == player->getBullet().y){
			map->tile[i] = arcade::TileType::MY_SHOOT;			
		}
		else
			map->tile[i] = arcade::TileType::EMPTY;
	}	
}

void initWhere(arcade::WhereAmI *where, Player *player, arcade::CommandType buff) {
	where->type = buff;	
	where->lenght = 1;
	where->position[0].x = player->getPlayer().x; 
	where->position[0].y = player->getPlayer().y;
}

extern "C"
{
  void 					Play()
  {
	Player				p;
	// Enemy 				e;
	Powerup  			pwu;
	arcade::GetMap 		*map;
	arcade::WhereAmI 	*where;
	arcade::CommandType buff;

	map = new arcade::GetMap + (40 * 40) * sizeof(arcade::TileType);
	where = new arcade::WhereAmI + 1 * sizeof(arcade::Position);
	while (read(0, &buff, sizeof(arcade::CommandType)) != -1) {
		initMap(map, &p, buff);
		initWhere(where, &p, buff);
		if (buff == arcade::CommandType::GET_MAP) {
			write(1, map, sizeof(arcade::GetMap) + sizeof(arcade::TileType) * 40 * 40);
		}
		if (buff == arcade::CommandType::WHERE_AM_I) {
			write(1, where, sizeof(arcade::WhereAmI) + 1 * sizeof(arcade::Position));
		}
		if (buff == arcade::CommandType::GO_UP || buff == arcade::CommandType::GO_DOWN
			|| buff == arcade::CommandType::GO_LEFT || buff == arcade::CommandType::GO_RIGHT
			|| buff == arcade::CommandType::GO_FORWARD || buff == arcade::CommandType::SHOOT)
			setDirection(&p, buff);		
		if (buff == arcade::CommandType::PLAY){
			p.movePlayer();
			// e.move();
		}
	}
  }
}