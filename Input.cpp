#include "Input.h"
#include "Game.h"

bool Input::keys[256];

void Input::input(ALLEGRO_EVENT *ev){
	if(ev->type == ALLEGRO_EVENT_KEY_DOWN){
		switch(ev->keyboard.keycode){
		case ALLEGRO_KEY_Q:
			Game::gameState = 0;
			break;
		case ALLEGRO_KEY_W:
			Input::keys[0] = true;
			break;
		case ALLEGRO_KEY_S:
			Input::keys[1] = true;
			break;
		case ALLEGRO_KEY_A:
			Input::keys[2] = true;
			break;
		case ALLEGRO_KEY_D:
			Input::keys[3] = true;
			break;
		case ALLEGRO_KEY_UP:
			Input::keys[0] = true;
			break;
		case ALLEGRO_KEY_DOWN:
			Input::keys[1] = true;
			break;
		case ALLEGRO_KEY_LEFT:
			Input::keys[2] = true;
			break;
		case ALLEGRO_KEY_RIGHT:
			Input::keys[3] = true;
			break;
		}
	}
	else if(ev->type == ALLEGRO_EVENT_KEY_UP){
		switch(ev->keyboard.keycode){
		case ALLEGRO_KEY_Q:
			Game::gameState = 0;
			break;
		case ALLEGRO_KEY_W:
			Input::keys[0] = false;
			break;
		case ALLEGRO_KEY_S:
			Input::keys[1] = false;
			break;
		case ALLEGRO_KEY_A:
			Input::keys[2] = false;
			break;
		case ALLEGRO_KEY_D:
			Input::keys[3] = false;
			break;
		case ALLEGRO_KEY_UP:
			Input::keys[0] = false;
			break;
		case ALLEGRO_KEY_DOWN:
			Input::keys[1] = false;
			break;
		case ALLEGRO_KEY_LEFT:
			Input::keys[2] = false;
			break;
		case ALLEGRO_KEY_RIGHT:
			Input::keys[3] = false;
			break;
		}
	}

};