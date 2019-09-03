#include "board.h"
#include "colors.h"
#include "lifeform.h"
#include <SDL2/SDL.h>
#include <time.h>
#include <stdio.h>

Board::Board(void)
{
	rect.h = BOX_SIZE;
	rect.w = BOX_SIZE;
	srand(time(0));
}

void Board::start()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
	seed();
}

void Board::seed()
{
	for(int i = 0 ; i < BOX_COUNT; ++i) {
		int x = i % ROW_SIZE;
		int y = i / ROW_SIZE;
		int xPosition = BOX_SIZE * x;
		int yPosition = BOX_SIZE * y;
		Lifeform *life = new Lifeform();
		grid[i] = life;
	}
}

void Board::update()
{
	for(int i = 0 ; i < BOX_COUNT; ++i) {
		int x = i % ROW_SIZE;
		int y = i / ROW_SIZE;
		int xPosition = BOX_SIZE * x;
		int yPosition = BOX_SIZE * y;
		Lifeform *life = grid[i];
		Lifeform *up = grid[getUp(i)];
		Lifeform *down = grid[getDown(i)];
		Lifeform *left = grid[i - 1 / ROW_SIZE];
		Lifeform *right = grid[x + 1 * ROW_SIZE];
		SDL_Color color = life->getColor();
		if (up->getColor().r > 0 ) {
		  life->fade(1,1,1);
		}
		if (down->getColor().g > 0 ) {
			life->fade(1,1,1);
		}
		drawBox(xPosition, yPosition, color);
	}
}

int Board::getUp(int i) {
  int columns = ROW_SIZE;
  int rows = ROW_COUNT;
  if (i / columns == 0 ) { // first row
    int result = columns * (rows - 1) + i;
    return result;
  }
  int result = i - columns;
  return result;
};

int Board::getDown(int i) {
  int columns = ROW_SIZE;
  int rows = ROW_COUNT;
  if (i / columns == rows - 1 ) { // last row
    int result =  i - (rows - 1) * columns;
    return result;
  }
  int result = i + columns;
  return result;
};

const int Board::BOX_SIZE = 32;
const int Board::HEIGHT = 480;
const int Board::WIDTH = 640;
const int Board::ROW_SIZE = Board::WIDTH / Board::BOX_SIZE;
const int Board::BOX_COUNT = (Board::HEIGHT / Board::BOX_SIZE) * Board::ROW_SIZE;
const int Board::ROW_COUNT = Board::BOX_COUNT / Board::ROW_SIZE;

void Board::setDrawColor(SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Board::drawBox(int x, int y, SDL_Color color)
{
	rect.x = x;
	rect.y = y;
	setDrawColor(color);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderFillRect(renderer, &rect);
}

void Board::draw()
{
	update();
	SDL_RenderPresent(renderer);
}
