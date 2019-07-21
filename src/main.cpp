#include <emscripten.h>
#include "board.h"

Board board;

void loop()
{
  board.draw();
}

int main()
{
	board.start();
  emscripten_set_main_loop(loop, 0, 1);
  return 0;
}
