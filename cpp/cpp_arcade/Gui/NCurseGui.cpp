#include "NCurseGui.hpp"
#include <unistd.h>

NCurseGui::NCurseGui() {
	initscr();
	start_color();
	clear();
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	nodelay(stdscr, true);
	keypad(stdscr, true);
	cbreak();
	noecho();
	curs_set(0);
	getmaxyx(stdscr, height, width);
	if (height < 42 || width < 40) {
		nodelay(stdscr, false);
		endwin();		
		exit(0);
	}
	width = 40;
	height = 42;
}

NCurseGui::~NCurseGui() {
	nodelay(stdscr, false);
	keypad(stdscr, false);	
	endwin();
}

void 	NCurseGui::init() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			drawRect(i, j, BLACK);
		}
	}
	for (int i = 0; i < width - 1; i++)
		drawRect((height - 2) * BLOCK, i * BLOCK, WHITE);
	for (int i = 0; i < height-1; i++)
		drawRect(i * BLOCK, (width - 2) * BLOCK, WHITE);
	for (int i = 0; i < width - 1; i++)
		drawRect(0, i * BLOCK, WHITE);
	for (int i = 0; i < height - 1; i++)
		drawRect(i * BLOCK, 0, WHITE);	
}

void 	NCurseGui::drawText(std::string text, int x, int y) {
	move(y / 10 - 1, x / 10);
	attrset(COLOR_PAIR(6));
	printw("%s", text.c_str());
}

void 	NCurseGui::drawRect(short x, short y, int color, unsigned short w, unsigned short h) {
	move(y / 10, x / 10);
	attrset(COLOR_PAIR(color));
	h = h;
	w = w;
	printw(" ");
}

void 	NCurseGui::clearGui() {
	clear();
}

void 	NCurseGui::initDraw() {
	init();
}

void 	NCurseGui::endDraw() {

}

void 	NCurseGui::closeGui() {
	nodelay(stdscr, false);
	keypad(stdscr, false);	
	endwin();
}

char 	NCurseGui::HandleEvent() {
   int 	tmp;

   tmp = getch();
   switch(tmp)
   {
        case KEY_LEFT:
			return ('l');
			break;
        case KEY_UP:
			return ('u');
			break;
        case KEY_DOWN:
			return ('d');
			break;
        case KEY_RIGHT:
			return ('r');
			break;
        case KEY_BACKSPACE:
			return ('q');
			break;
		case 27:
			return ('q');
			break;		
		case 112:
			return ('p');
			break;
		case '2':
            return ('2');
            break;
        case '\"':
            return ('3');
            break;
        case '\'':
            return ('4');
            break;
        case '(':
            return ('5');					
		default:
			return ('\0');
			break;
   }
}

extern "C" {
	IGui *create_gui()
	{
		return new NCurseGui();
	}
}