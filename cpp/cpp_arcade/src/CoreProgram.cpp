#include <dlfcn.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "CoreProgram.hpp"

CoreProgram::CoreProgram() : 
handleGui(NULL), handleGame(NULL), gui(NULL),
game(NULL), curGui(""), curGame(""), usrName(""), point(-1) 
{}

CoreProgram::~CoreProgram() {
	if (handleGui != NULL) {
		dlclose(handleGui);
	}
	if (handleGame != NULL) {
		dlclose(handleGame);
	}
}

void	CoreProgram::setGuis() {
	std::system("ls lib/ > lib.txt"); // execute the UNIX command "ls /libs > libs.txt"

	std::ifstream file("lib.txt");
	std::string str;
	while(std::getline(file, str)) {
		guis.push_back("lib/" + str);
	}

	std::system("rm lib.txt");
}

std::vector<std::string> 	CoreProgram::getGuis() const {
	return guis;
}

void	CoreProgram::setGames() {
	std::system("ls games/ > games.txt"); // execute the UNIX command "ls /games > games.txt"
	
	std::ifstream file("games.txt");
	std::string str;
	while(std::getline(file, str)) {
		games.push_back("games/" + str);
	}
	std::system("rm games.txt");
}

std::vector<std::string> 	CoreProgram::getGames() const {
	return games;
}

IGui 	*CoreProgram::loadIGui(std::string file) {
	IGui* (*creator)();
	
	handleGui = dlopen(file.c_str(), RTLD_LAZY);
	if (handleGui == NULL) 
		return(NULL);
	
	creator = reinterpret_cast<IGui* (*)()>(dlsym(handleGui, "create_gui"));
	if (creator == NULL) {
		return(NULL);
	}
	if (file.compare("lib/lib_arcade_ncurses.so") == 0 && gui != NULL) {

		gui->closeGui();
	}
	gui = creator();
	curGui = file;
	return gui;
}

IGui 	*CoreProgram::getGui() const {
	return gui;
}

IGame 	*CoreProgram::loadIGame(std::string file, IGui *gui) {
	IGame* (*external_creator)(IGui *);

	handleGame = dlopen(file.c_str(), RTLD_LAZY);
	if (handleGame == NULL)
		return(NULL);

	external_creator = reinterpret_cast<IGame* (*)(IGui *)>(dlsym(handleGame, "create_game"));
	if (external_creator == NULL)
		return(NULL);

	game = external_creator(gui); //Object included from the library !
	curGame = file;
	return game;
}

IGame 	*CoreProgram::getGame() const {
	return game;
}

std::string 	CoreProgram::getCurGui() const {
	return curGui;
}

std::string 	CoreProgram::getCurGame() const {
	return curGame;
}

void 			CoreProgram::changeGui(char c) {	
	unsigned int i;
	for (i = 0; i != guis.size(); i++){
		if (guis[i].compare(curGui) == 0)
			break;
	}
	if (c == '2'){
		if (i == 0)
			i = guis.size() - 1;
		else
			i--;
	}
	else if (c == '3'){
		if (i + 1 == guis.size())
			i = 0;
		else
			i++;
	}
	if (curGui.compare("lib/lib_arcade_ncurses.so") == 0) {
		gui->closeGui();
	}	
	loadIGui(guis[i]);
	game->setGui(gui);
}

void 			CoreProgram::changeGame(char c) {
	unsigned int i;
	for (i = 0; i != games.size(); i++){
		if (games[i].compare(curGame) == 0)
			break;
	}
	if (c == '4'){
		if (i == 0)
			i = games.size() - 1;
		else
			i--;
	}
	else if (c == '5'){
		if (i + 1 == games.size())
			i = 0;
		else
			i++;
	}
	gui->clearGui();
	loadIGame(games[i], gui);
}

void 			CoreProgram::saveScore() {
	std::ofstream 	file;

	gui->closeGui();
	std::cout << std::endl << "-------- YOUR SCORE ------------" << std::endl << std::endl;
	std::cout << "\E[32;1m" << "             " << game->getPoint() << "\E[m" << std::endl;
	std::cout << std::endl << "-------------------------------" << std::endl << std::endl;	
	std::cout << "Enter your name: ";
	std::cin >> usrName;
	if (curGame.compare("games/lib_arcade_snake.so") == 0)
		file.open("score_snake.txt", std::fstream::app);
	else if (curGame.compare("games/lib_arcade_solarfox.so") == 0)
		file.open("score_solarfox.txt", std::fstream::app);		
	file << usrName << ": " << game->getPoint() << std::endl;
	file.close();
	point = game->getPoint();

	if (curGame.compare("games/lib_arcade_snake.so") == 0) {
		orderScore("score_snake.txt");
	}
	else if (curGame.compare("games/lib_arcade_solarfox.so") == 0) {
		orderScore("score_solarfox.txt");
	}
}

void 			CoreProgram::orderScore(std::string const &f) {
	std::fstream 				file;
	std::vector<std::string>  	save;	
	std::string					tmp;
	std::size_t 				find;

	file.open(f);
	while (getline(file, tmp)) {
		save.push_back(tmp);
	}
	file.close();
	std::sort (save.begin(), save.end(), sort_function);
	file.open(f,  std::ofstream::out | std::ofstream::trunc);
	for (unsigned int i = 0; i < save.size(); i++)
		file << save[i] << std::endl;
	std::cout << std::endl << "-------- HIGHSCORE ------------" << std::endl << std::endl;
	for (unsigned int i = 0; i < save.size(); i++) {
		find = save[i].find(":");
		tmp = save[i].substr(0, find);
		if (tmp.compare(usrName) == 0 && atoi(save[i].substr(find + 1).c_str()) > game->getPoint())
			std::cout << "\E[34;1m" << save[i] << "\E[m" << std::endl;		
		else if (tmp.compare(usrName) == 0 && atoi(save[i].substr(find + 1).c_str()) == game->getPoint())
			std::cout << "\E[32;1m" << save[i] << "\E[m" << std::endl;
		else if (tmp.compare(usrName) == 0)
			std::cout << "\E[31;1m" << save[i] << "\E[m" << std::endl;
		else
			std::cout << save[i] << std::endl;
	}
	std::cout << std::endl << "-------------------------------" << std::endl << std::endl;
}

int 			CoreProgram::restart() {
	std::string 	ans;

	std::cout << "Would you like to restart ? type y for restart or n for quit: ";
	std::cin >> ans;
	if (ans.compare("n") == 0) {
		return 1;
	}
	loadIGui(curGui);
	loadIGame(curGame, gui);
	return 0;
}

void 			CoreProgram::clearCore() {
	delete gui;
	delete game;
}