#ifndef BOARD_H
#define BOARD_H
#include <SDL2/SDL.h>
#include "board.h"
#include "lifeform.h"

class Board
{
	static const int BOX_SIZE;
	static const int HEIGHT;
	static const int WIDTH;
	static const int ROW_SIZE;
	static const int BOX_COUNT;
	static const int ROW_COUNT;
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Rect rect;
	void setDrawColor(SDL_Color color);
	void drawBox(int x, int y, SDL_Color color);
	void update();
	void seed();
	int getUp(int i);
	int getDown(int i);
  public:
		Board();
		Lifeform *grid[600];
		Lifeform *grid2[600];
		void draw();
		void start();

};
#endif /* BOARD_H */
