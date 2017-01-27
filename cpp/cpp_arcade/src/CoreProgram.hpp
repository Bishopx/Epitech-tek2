#ifndef CORE_PROGRAM_HPP
# define CORE_PROGRAM_HPP

#include <vector>
#include "IGame.hpp"
#include "IGui.hpp"

class CoreProgram {
	void 						*handleGui;
	void 						*handleGame;
	IGui 						*gui;
	IGame 						*game;
	std::vector<std::string>	games;
	std::vector<std::string>	guis;
	std::string 				curGui;
	std::string 				curGame;
	std::string 				usrName;
	int 						point;
	
public:
	CoreProgram();
	~CoreProgram();
	void						setGuis();
	std::vector<std::string>	getGuis() const;
	void 						setGames();
	std::vector<std::string>	getGames() const;
	IGui						*loadIGui(std::string);
	IGui 						*getGui() const;
	IGame 						*loadIGame(std::string, IGui *);
	IGame 						*getGame() const;
	std::string 				getCurGui() const;
	std::string 				getCurGame() const;
	void 						changeGui(char);
	void 						changeGame(char);
	void 						saveScore();

	void 						orderScore(std::string const &);
	int 						restart();
	void 						clearCore();

};

int 	play(CoreProgram *);
int 	load(CoreProgram *, std::string);
bool 	sort_function(std::string, std::string);

#endif