#ifndef GL_GUI_HPP
# define GL_GUI_HPP

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/freeglut.h>
# include <sstream>
# include "IGui.hpp"

class GlGui : public IGui {
	double 			width, height;
	char 			last;
	std::vector<int *> color;
	SDL_Surface 	*screen;
	TTF_Font 		*font;	

public:
	GlGui();
	~GlGui();
	void 	drawLimit();
	void 	drawText(std::string text, int x, int y);
	void 	drawRect(short x, short y, int color, unsigned short w = 10, unsigned short h = 10);
	void 	closeGui();	
	void 	initDraw();
	void 	clearGui();
	void 	endDraw();	
	char 	HandleEvent();
};

#endif