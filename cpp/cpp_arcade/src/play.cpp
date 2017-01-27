#include <algorithm>
#include "IGame.hpp"
#include "IGui.hpp"
#include "CoreProgram.hpp"

bool sort_function(std::string a, std::string b) {
	int tmpa;
	int tmpb;
	std::size_t find;

	find = a.find(":");
	a = a.substr(find + 2);
	find = b.find(":");
	b = b.substr(find + 2);
	tmpa = atoi(a.c_str());
	tmpb = atoi(b.c_str());

	return (tmpa > tmpb);
}

int 	load(CoreProgram *core, std::string file) {
	if (file.find("games/")!= std::string::npos) {
		if (!core->loadIGui(core->getGuis()[0])){
			std::cout << "Error could not load Gui" << std::endl;
			return 1;
		}
		if (!core->loadIGame(file, core->getGui())) {
			delete core->getGui();
			std::cout << "Error could not load Game" << std::endl;
			return 1;
		}
	}
	else if (file.find("lib/") != std::string::npos) {
		if (!core->loadIGui(file)){
			std::cout << "Error could not load Gui" << std::endl;
			return 1;
		}
		if (!core->loadIGame(core->getGames()[0], core->getGui())) {
			std::cout << "Error could not load Game" << std::endl;
			return 1;
		}
	}
	else {
		std::cout << "Error: " << file << " does not exist" << std::endl;
		return 1;
	}
	return 0;
}

int 	play(CoreProgram *core) {
	char c;

	while (1){
		c = core->getGame()->PlayGame();
		if (c == '2' || c == '3')
			core->changeGui(c);
		else if (c == '4' || c == '5')
			core->changeGame(c);
		else if (c == 'q') {
			core->clearCore();
			return (0);
		}
		else if (c == 'g') {
			core->saveScore();
			if (core->restart() == 1) {
				core->clearCore();
				return (0);
			}
		}
	}
	return (0);
}