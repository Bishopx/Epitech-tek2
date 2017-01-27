#ifndef SDL_GUI_HPP
# define SDL_GUI_HPP

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <sstream>
# include <vector>
# include "IGui.hpp"

class SdlGui : public IGui {
	int 					width, height;
	SDL_Surface 			*screen;
	TTF_Font 				*font;
	std::vector<Uint32> 	color;

public:
	SdlGui();
	~SdlGui();
	void 	drawRect(short x, short y,int color, unsigned short w = 10, unsigned short h = 10);
	void 	drawText(std::string text, int x, int y);	
	void 	closeGui();	
	void 	initDraw();
	void 	clearGui();
	void 	endDraw();
	char 	HandleEvent();
};

#endif