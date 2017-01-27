#include <algorithm>
#include "IGame.hpp"
#include "IGui.hpp"
#include "CoreProgram.hpp"

int 	main(int ac, char** av) {
	CoreProgram 	core;

	if (ac < 2)
	{
		std::cerr << "Usage : ./exemple4 <libXXX.so>" << std::endl;
		return(1);
	}
	core.setGames();
	core.setGuis();
	std::string	file = av[1];
	if (load(&core, file) == 1)
		return (1);
	play(&core);
	return (0);
}