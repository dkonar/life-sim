#include "lifeform.h"
#include <SDL2/SDL.h>
#include "colors.h"

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
