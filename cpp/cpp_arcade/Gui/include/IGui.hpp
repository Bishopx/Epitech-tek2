#ifndef IGUI_HPP
# define IGUI_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include "macro.hpp"

class IGui {

public:
	virtual ~IGui() {}
	virtual void drawRect(short, short, int, unsigned short w = 10, unsigned short h = 10) = 0;
	virtual void initDraw() = 0;
	virtual void endDraw() = 0;
	virtual void closeGui() = 0;
	virtual void clearGui() = 0;
	virtual void drawText(std::string text, int x, int y) = 0;
	virtual char HandleEvent() = 0;
};

#endif