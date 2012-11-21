#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <iostream>
#include "Game.h"
#include "Input.h"
#include "VariousColors.h"
#include "Camera.h"

void drawStar(float x, float y, ALLEGRO_COLOR C);

int main(int argc, char *argv[])
{
	bool doLogic = false;
	bool redraw = false;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *drawTimer;
	ALLEGRO_TIMER *logicTimer;
	ALLEGRO_DISPLAY_MODE disp_data;
	ALLEGRO_BITMAP *StarBackgroundLayer1;
	ALLEGRO_BITMAP *StarBackgroundLayer2;
	ALLEGRO_BITMAP *StarBackgroundLayer3;
	ALLEGRO_BITMAP *StarBackgroundLayer4;
	ALLEGRO_BITMAP *StarBackgroundGalaxy1;

	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	al_init_image_addon();
	al_set_new_display_flags(ALLEGRO_FRAMELESS);
	al_get_display_mode(al_get_num_display_modes()-1, &disp_data);

	display = al_create_display(disp_data.width, disp_data.height);
	event_queue = al_create_event_queue();
	drawTimer = al_create_timer(1.0/60.0);
	logicTimer = al_create_timer(1.0/120.0);
	
	
	StarBackgroundLayer1 = al_create_bitmap(disp_data.width, disp_data.height);
	StarBackgroundLayer2 = al_create_bitmap(disp_data.width, disp_data.height);
	StarBackgroundLayer3 = al_create_bitmap(disp_data.width, disp_data.height);
	StarBackgroundLayer4 = al_create_bitmap(disp_data.width, disp_data.height);
	StarBackgroundGalaxy1 = al_create_bitmap(disp_data.width, disp_data.height);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(drawTimer));
	al_register_event_source(event_queue, al_get_timer_event_source(logicTimer));
	al_start_timer(drawTimer);
	al_start_timer(logicTimer);
	al_set_mouse_xy(display, 500, 500);
	al_hide_mouse_cursor(display);
	al_set_target_bitmap(StarBackgroundLayer1);

	for(int i = 0; i < 200; i++)
	{
		drawStar(rand() % 1920, rand() % 1080, RANDOM);
	};
	al_set_target_bitmap(StarBackgroundLayer2);
	for(int i = 0; i < 100; i++)
	{
		drawStar(rand() % 1920, rand() % 1080, RANDOM);
	};
	al_set_target_bitmap(StarBackgroundLayer3);
	for(int i = 0; i < 100; i++)
	{
		drawStar(rand() % 1920, rand() % 1080, RANDOM);
	};
	al_set_target_bitmap(StarBackgroundLayer4);
	for(int i = 0; i < 100; i++)
	{
		drawStar(rand() % 1920, rand() % 1080, RANDOM);
	};
	al_set_target_bitmap(StarBackgroundGalaxy1);
	for(int i = 0; i <= 1000; i += 5)
	{
		drawStar(400 + cos(i) * i/16, 300 + sin(i) * i/16, RANDOM);
	};
	for(int i = 0; i <= 1000; i += 5)
	{
		drawStar(800 + cos(i) * i/4, 600 + sin(i) * i/4, RANDOM);
	};
	al_set_target_backbuffer(display);

	Camera cam;
	cam.x = disp_data.width/2;
	cam.y = disp_data.height/2;

	while(Game::gameState == 1){
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_TIMER && ev.timer.source == drawTimer){
			redraw = true;
		}else if(ev.type == ALLEGRO_EVENT_TIMER && ev.timer.source == logicTimer){
			doLogic = true;
		}else{
			Input::input(&ev);
		}

		if(doLogic && al_is_event_queue_empty(event_queue)){
			doLogic = false;
			if(Input::keys[0]) cam.y -= 5;
			else if(Input::keys[1]) cam.y += 5;
			else if(Input::keys[2]) cam.x -= 5;
			else if(Input::keys[3]) cam.x += 5;
		}


		if(redraw && al_is_event_queue_empty(event_queue)){
			redraw = false;
			al_clear_to_color(BLACK);
			al_draw_bitmap(StarBackgroundGalaxy1, 200 - cam.x/128, 200 - cam.y/128, 0);
			al_draw_bitmap(StarBackgroundLayer1, 1920 - cam.x/8 + (disp_data.width * ceil((int)cam.x/8 / 1920)), 0 - cam.y/8, 0);
			al_draw_bitmap(StarBackgroundLayer1, 0 - cam.x/8 + (disp_data.width * ceil((int)cam.x/8 / 1920)), 0 - cam.y/8, 0);
			al_draw_bitmap(StarBackgroundLayer1, 1920 - cam.x/8 + (disp_data.width * ceil((int)cam.x/8 / 1920)), 0 - cam.y/8, 0);

			al_draw_bitmap(StarBackgroundLayer1, 0 - cam.x/8, 0 - cam.y/8 + (disp_data.height * ceil((int)cam.y/8 / disp_data.height)), 0);
			al_draw_bitmap(StarBackgroundLayer1, 1920 - cam.x/8, 1080 - cam.y/8 + (disp_data.height * ceil((int)cam.y/8 / disp_data.height)), 0);

			al_draw_bitmap(StarBackgroundLayer2, -1920 - cam.x/4 + (disp_data.width * ceil((int)cam.x/4 / 1920)), 0 - cam.y/4, 0);
			al_draw_bitmap(StarBackgroundLayer2, 0 - cam.x/4 + (disp_data.width * ceil((int)cam.x/4 / 1920)), 0 - cam.y/4, 0);
			al_draw_bitmap(StarBackgroundLayer2, 1920 - cam.x/4 + (disp_data.width * ceil((int)cam.x/4 / 1920)), 0 - cam.y/4, 0);

			al_draw_bitmap(StarBackgroundLayer3, -1920 - cam.x/2 + (disp_data.width * ceil((int)cam.x/2 / 1920)), 0 - cam.y/2, 0);
			al_draw_bitmap(StarBackgroundLayer3, 0 - cam.x/2 + (disp_data.width * ceil((int)cam.x/2 / 1920)), 0 - cam.y/2, 0);
			al_draw_bitmap(StarBackgroundLayer3, 1920 - cam.x/2 + (disp_data.width * ceil((int)cam.x/2 / 1920)), 0 - cam.y/2, 0);

			al_draw_bitmap(StarBackgroundLayer4, -1920 - cam.x + (disp_data.width * ceil((int)cam.x / 1920)), 0 - cam.y, 0);
			al_draw_bitmap(StarBackgroundLayer4, 0 - cam.x + (disp_data.width * ceil((int)cam.x / 1920)), 0 - cam.y, 0);
			al_draw_bitmap(StarBackgroundLayer4, 1920 - cam.x + (disp_data.width * ceil((int)cam.x / 1920)), 0 - cam.y, 0);

			al_flip_display();
		}
	}
	return 0;
};

void drawFibonnaciCircle(float x, float y, int points)
{
	for(int i = 0; i < points; i++)
	{
		al_draw_arc(x, y, 10, ALLEGRO_PI/4, ALLEGRO_PI/4, GREEN, 5);
	};
};

void drawStar(float x, float y, ALLEGRO_COLOR C)
{
	al_draw_pixel(x+1, y, C);
	al_draw_pixel(x-1, y, C);
	al_draw_pixel(x, y+1, C);
	al_draw_pixel(x, y-1, C);
	al_draw_pixel(x, y, C);

};