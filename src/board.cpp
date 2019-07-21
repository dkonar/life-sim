#include "board.h"
#include "colors.h"
#include <SDL2/SDL.h>
#include <time.h>
#include <stdio.h>

Lifeform::Lifeform() {
	color = Colors::randomColor();
};

SDL_Color Lifeform::getColor() const {
  return color;
}

void Lifeform::fade(char r, char g, char b) {
  if (this->color.r > 0) {
		this->color.r -= r;
	}
	if (this->color.g > 0) {
		this->color.g -= g;
  }
	if (this->color.b > 0) {
		this->color.b -= b;
	}
}

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
		SDL_Color color = life->getColor();
		life->fade(1,1,1);
		drawBox(xPosition, yPosition, color);
	}
}

const int Board::BOX_SIZE = 32;
const int Board::HEIGHT = 480;
const int Board::WIDTH = 640;
const int Board::ROW_SIZE = Board::WIDTH / Board::BOX_SIZE;
const int Board::BOX_COUNT = (Board::HEIGHT / BOX_SIZE) * Board::ROW_SIZE;

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
