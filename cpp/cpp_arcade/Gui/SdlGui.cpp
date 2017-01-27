#include "SdlGui.hpp"

SdlGui::SdlGui() {
	width = WIDTH;
	height = HEIGHT;
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	font = TTF_OpenFont("./air.ttf", 16);
  	SDL_WM_SetCaption("Arcade SDL", NULL);
	screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
  	color.push_back(SDL_MapRGB(screen->format,0x00,0x00,0x00));
  	color.push_back(SDL_MapRGB(screen->format,0xff,0xff,0xff));
  	color.push_back(SDL_MapRGB(screen->format,0xff,0x00,0x00));
  	color.push_back(SDL_MapRGB(screen->format,0x00,0xff,0x00));
  	color.push_back(SDL_MapRGB(screen->format,0x00,0x00,0xff));
  	color.push_back(SDL_MapRGB(screen->format,0xff,0x00,0xff));	
}

SdlGui::~SdlGui() {
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
}

void 	SdlGui::drawText(std::string text, int x, int y) {
	SDL_Surface *w;
	SDL_Rect 	tmp;
	SDL_Color 	white;

	white.r = 255;
	white.g = 255;
	white.b = 255;
	tmp.x = x;
	tmp.y = y;
	w = TTF_RenderText_Solid(font, text.c_str(), white);
	drawRect(0, y, BLACK, 400, 20);		
	SDL_BlitSurface(w, NULL, screen, &tmp);	
	SDL_FreeSurface(w);		
}

void 	SdlGui::drawRect(short x, short y,int c, unsigned short w, unsigned short h) {
	SDL_Rect tmp = { x, y, w, h };
	SDL_FillRect(screen,&tmp,color[c]);
}

void 	SdlGui::initDraw() {
	drawRect(0,0, RED,width,10);
	drawRect(0,0, RED,10,height-20);
	drawRect(0,height-30, RED,width,10);
	drawRect(width-10,0, RED,10,height-20);
}

void 	SdlGui::endDraw() {
	SDL_Flip(screen);
}

void 	SdlGui::closeGui() {
	SDL_Quit();
}

void 	SdlGui::clearGui() {
	for (unsigned short i = 0; i < height; i++) {
		for (unsigned short j = 0; j < width; j++) {
			drawRect(j, i, BLACK);
		}
	}
}

char 	SdlGui::HandleEvent() {
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
					case SDLK_LEFT:
						return ('l');
						break;
					case SDLK_UP:
						return ('u');
						break;
					case SDLK_DOWN:
						return ('d');
						break;
					case SDLK_RIGHT:
						return ('r');
						break;
					case SDLK_ESCAPE:
						return ('q');
						break;
					case SDLK_p:
						return ('p');
						break;
					case 233:
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
						return '0';
						break;
			}
		} else if(event.type == SDL_QUIT)
			return ('q');
	}
	return '\0';
}

extern "C" {
	IGui *create_gui()
	{
		return new SdlGui();
	}
}
