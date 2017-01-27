#ifndef IGAME_HPP
# define IGAME_HPP

# include "IGui.hpp"

class IGame {

public:
	virtual ~IGame() {}
	virtual char PlayGame() = 0;
	virtual void setGui(IGui *) = 0;
	virtual int getPoint() const = 0;
};

#endif