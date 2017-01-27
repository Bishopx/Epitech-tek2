#include "GlGui.hpp"
#include <unistd.h>

bool initglut = 0;

int 	*init_color(int x, int y, int z) {
	int *color;

	color = (int *) malloc(sizeof (int) * 3);
	color[0] = x;
	color[1] = y;
	color[2] = z;
	return color;
}

GlGui::GlGui() {
	int 	ac = 1;
	char 	*av[1];

	av[0] = strdup("GlutInit");
	width = WIDTH;
	height = HEIGHT;
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(width, height, 32, SDL_OPENGL);	
  	SDL_WM_SetCaption("Arcade OpenGl", NULL);
  	color.push_back(init_color(0, 0, 0));
  	color.push_back(init_color(255, 255, 255));
  	color.push_back(init_color(255, 0, 0));
  	color.push_back(init_color(0, 255, 0));
  	color.push_back(init_color(0, 0, 255));
  	color.push_back(init_color(255, 0, 255));
  	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();
  	gluOrtho2D(0, width, 0, height);
  	SDL_EnableKeyRepeat(10, 10);
  	if (!initglut) {
  		glutInit(&ac, av);  	
  		initglut = 1;
  	}
}

GlGui::~GlGui() {
	SDL_Quit();
}

void 	GlGui::drawLimit() {
	for (int i = 0; i < width; i+= 10)
		drawRect(i, 5, RED);
	for (int i = 0; i < width; i+= 10)
		drawRect(i, height - 30, RED);
	for (int i = 0; i < height - 30; i+= 10)
		drawRect(0, i, RED);
	for (int i = 0; i < height - 30; i+= 10)
		drawRect(width - 10, i, RED);	
}

void 	GlGui::drawText(std::string text, int x, int y) {
    glColor3ub(255, 255, 255);	
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 400, 0, 400, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, height - y - 10);
	for (unsigned int i = 0; i < text.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int) text[i]);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void 	GlGui::drawRect(short x, short y, int c, unsigned short w, unsigned short h) {
	h = h;
	w = w;
  	glLoadIdentity();
   	glTranslated(x, abs(y - WIDTH), 0);
    glColor3ub(color[c][0], color[c][1], color[c][2]);	
    glBegin(GL_QUADS);
    glVertex2d(0,-5);
    glVertex2d(0,5);
    glVertex2d(10,5);
    glVertex2d(10,-5);
    glEnd();
}

void 	GlGui::clearGui() {
	for (unsigned short i = 0; i < height; i++) {
		for (unsigned short j = 0; j < width; j++) {
			drawRect(j, i, BLACK);
		}
	}
}

void 	GlGui::initDraw() {
	glClear(GL_COLOR_BUFFER_BIT);
  	glMatrixMode(GL_MODELVIEW);
	drawLimit();  	
}

void 	GlGui::endDraw() {
	glFlush();
	SDL_GL_SwapBuffers();	
}

void 	GlGui::closeGui() {
	SDL_Quit();
}

char 	GlGui::HandleEvent() {
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
						return '\0';
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
		return new GlGui();
	}
}
