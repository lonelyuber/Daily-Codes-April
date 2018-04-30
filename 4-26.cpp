#include <stdio.h>
#include <iostream>
using namespace std;
#include <allegro5/allegro.h>
#include<allegro5\allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include<math.h>
#include<cmath>

const float FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 600;
const int BOUNCER_SIZE = 32;

int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *bouncer2 = NULL;
	ALLEGRO_BITMAP *bouncer3 = NULL;
	ALLEGRO_BITMAP *background = NULL;
	// Bouncer
	float bouncer_x = SCREEN_W / 10 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 8 - BOUNCER_SIZE / 2.0;
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	// Bouncer 2
	float bouncer2_x = SCREEN_W / 2.5 - BOUNCER_SIZE / 2.0;
	float bouncer2_y = SCREEN_H / 6.5 - BOUNCER_SIZE / 2.0;
	float bouncer2_dx = -4, bouncer2_dy = 4;
	// Bouncer 3
	float bouncer3_x = SCREEN_W / 1.45 - BOUNCER_SIZE / 2.0;
	float bouncer3_y = SCREEN_H / 15 - BOUNCER_SIZE / 2.0;
	float bouncer3_dx = -4, bouncer3_dy = 4;
	bool redraw = true;

	// Math
	int angle = 1;
	int a = 0;
	int b = 0;
	int radius = 1;
	int delay = 1;

	al_init();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);
	al_init_image_addon();

	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);

	// Load
	sample = al_load_sample("Tropicana.wav");

	background = al_load_bitmap("Roxbury.jpg");
	bouncer = al_load_bitmap("Cage.png");
	bouncer2 = al_load_bitmap("Obama.png");
	bouncer3 = al_load_bitmap("Drake.png");

	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) { //physics engine
											  // Bouncer
			bouncer_x += a + tan(angle)*radius;
			bouncer_y += b + cos(angle)*radius;
			// Bouncer 2
			bouncer2_x += a + tan(angle)*radius;
			bouncer2_y += b + sin(angle)*radius;
			// Bouncer 3
			bouncer3_x += a + cos(angle)*radius;
			bouncer3_y += b + sin(angle)*radius;


			if (delay % 5 == 0)
				angle++;
			delay++;


			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
		//render section
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));

			//draw
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_draw_bitmap(bouncer2, bouncer2_x, bouncer2_y, 0);
			al_draw_bitmap(bouncer3, bouncer3_x, bouncer3_y, 0);

			al_flip_display();
		}
	}
	al_destroy_sample(sample);
	al_destroy_bitmap(background);
	al_destroy_bitmap(bouncer);
	al_destroy_bitmap(bouncer2);
	al_destroy_bitmap(bouncer3);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

//#include <allegro5\allegro.h>
//#include <allegro5\allegro_image.h>
//#include <allegro5\allegro_primitives.h>
//#include <cmath>
//
//int main() {
//	al_init_image_addon();
//	al_init();
//	ALLEGRO_DISPLAY *display = NULL;
//	ALLEGRO_TIMER *timer = NULL;
//	ALLEGRO_BITMAP *background = NULL;
//	ALLEGRO_BITMAP *image = NULL;
//	ALLEGRO_BITMAP *image2 = NULL;
//	ALLEGRO_BITMAP *image3 = NULL;
//	display = al_create_display(1280, 720);
//
//	// Timer
//	al_create_timer(1 / 60);
//
//	// Load
//	background = al_load_bitmap("Roxbury.gif");
//	image = al_load_bitmap("Obama.png");
//	image2 = al_load_bitmap("Cage.png");
//	image3 = al_load_bitmap("Ted.png");
//
//	al_clear_to_color(al_map_rgb(0, 0, 0));
//
//	// Draw
//	al_draw_bitmap(image, 200, 200, 0);
//	al_draw_bitmap(image2, 0, 0, 0);
//
//	al_flip_display();
//	al_set_window_position(display, 400, 200);
//	al_set_window_title(display, "Images");
//	al_destroy_display(display);
//
//}