#include "Snake.hpp"
#include "Food.hpp"
#include "Protocol.hpp"
#include <unistd.h>

void setDirection(Snake *snake, arcade::CommandType com) {
	if (com == arcade::CommandType::GO_UP && snake->getDirection() != 'd')
		snake->setDirection('u');
	if (com == arcade::CommandType::GO_DOWN && snake->getDirection() != 'u')
		snake->setDirection('d');
	if (com == arcade::CommandType::GO_LEFT && snake->getDirection() != 'r')
		snake->setDirection('l');
	if (com == arcade::CommandType::GO_RIGHT && snake->getDirection() != 'l')
		snake->setDirection('r');			
}

void initMap(arcade::GetMap *map, Food *f, arcade::CommandType buff) {
	int x;
	int y;

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
		else if (x == f->getFood().x && y == f->getFood().y)
			map->tile[i] = arcade::TileType::POWERUP;
		else
			map->tile[i] = arcade::TileType::EMPTY;
	}	
}

void initWhere(arcade::WhereAmI *where, Snake *s, arcade::CommandType buff) {
	where->type = buff;	
	where->lenght = s->getSnake().size();
	for (unsigned int i = 0; i < s->getSnake().size(); i++) {
		where->position[i].x = s->getSnake()[i].x; 
		where->position[i].y = s->getSnake()[i].y;
	}
}

extern "C"
{
  void 					Play()
  {
	Snake 				s;
	Food  				f;
	arcade::GetMap 		*map;
	arcade::WhereAmI 	*where;
	arcade::CommandType buff;

	map = new arcade::GetMap + (40 * 40) * sizeof(arcade::TileType);
	where = new arcade::WhereAmI + s.getSnake().size();
	while (read(0, &buff, sizeof(arcade::CommandType)) != -1) {
		initMap(map, &f, buff);
		initWhere(where, &s, buff);
		if (buff == arcade::CommandType::GET_MAP) {
			write(1, map, sizeof(arcade::GetMap) + sizeof(arcade::TileType) * 40 * 40);
		}
		if (buff == arcade::CommandType::WHERE_AM_I) {
			write(1, where, sizeof(arcade::WhereAmI) + s.getSnake().size() * sizeof(arcade::Position));
		}
		if (buff == arcade::CommandType::GO_UP || buff == arcade::CommandType::GO_DOWN
			|| buff == arcade::CommandType::GO_LEFT || buff == arcade::CommandType::GO_RIGHT
			|| buff == arcade::CommandType::GO_FORWARD)
			setDirection(&s, buff);		
		if (buff == arcade::CommandType::PLAY)
			s.moveSnake();
		s.collision(&f);
	}
  }
}