#include "colors.h"
#include <SDL2/SDL.h>

static const SDL_Color RED = { 255, 0, 0, 255 };
static const SDL_Color GREEN = { 0, 255, 0, 255 };
static const SDL_Color BLUE = { 0, 0, 255, 255 };
static const SDL_Color BLACK = { 0, 0, 0, 255 };

SDL_Color Colors::randomColor() {
	int color = rand() % 20;

	switch (color) {
		case 0: {
			return RED;
		}
		case 1: {
			return GREEN;
		}
		case 2: {
			return BLUE;
		}
		case 3: {
			return BLACK;
		}
		default: {
			return BLACK;
		}
	}
}
