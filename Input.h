#ifndef INPUT_H
#define INPUT_H

#include <allegro5\allegro.h>

class Input
{
public:
	static bool keys[256];
	static float mouseX;
	static float mouseY;
	static void input(ALLEGRO_EVENT *ev);
};


#endif