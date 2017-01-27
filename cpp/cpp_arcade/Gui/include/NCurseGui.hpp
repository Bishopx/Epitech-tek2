#ifndef NCURSE_GUI_HPP
# define NCURSE_GUI_HPP

# include <ncurses.h>
# include "IGui.hpp"

class NCurseGui : public IGui {
	int 			width, height;
	int 			point;

public:
	NCurseGui();
	~NCurseGui();
	// void 	drawGame(Snake *snake, Food *food);
	void 	init();
	void 	drawRect(short x, short y, int color, unsigned short w = 10, unsigned short h = 10);
	void 	drawText(std::string text, int x, int y);
	void 	closeGui();	
	void 	initDraw();
	void 	clearGui();
	void 	endDraw();
	char 	HandleEvent();
};

#endif