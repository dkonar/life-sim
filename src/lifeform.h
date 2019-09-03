#ifndef LIFEFORM_H
#define LIFEFORM_H
#include <SDL2/SDL.h>
#include "lifeform.h"

class Lifeform
{
	SDL_Color color;
	public:
		Lifeform();
		SDL_Color getColor() const;
		void fade(char r, char g, char b);
};

#endif /* LIFEFORM_H */
