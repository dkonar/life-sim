#ifndef BOARD_H
#define BOARD_H
#include <SDL2/SDL.h>
#include "board.h"
#include <array>
#include <emscripten.h>
class Lifeform
{
	SDL_Color color;
	public:
		Lifeform();
		SDL_Color getColor() const;
		void fade(char r, char g, char b);
};

class Board
{
	static const int BOX_SIZE;
	static const int HEIGHT;
	static const int WIDTH;
	static const int ROW_SIZE;
	static const int BOX_COUNT;
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Rect rect;
	void setDrawColor(SDL_Color color);
	void drawBox(int x, int y, SDL_Color color);
	void update();
	void seed();
  public:
		Board();
		Lifeform *grid[600];
		Lifeform *grid2[600];
		void draw();
		void start();

};
#endif /* BOARD_H */
