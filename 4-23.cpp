#include <stdio.h>
#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
using namespace std;


int collision(int ball_x, int ball_y, int paddle_x, int paddle_y, int paddle_w, int paddle_h, int ball_w, int ball_h, int paddle2_x, int paddle2_y, int paddle2_w, int paddle2_h);


//constants.
const int SCREEN_W = 1000;
const int SCREEN_H = 680;


int main(int argc, char **argv) {
	//Allegro variables.
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *ball = NULL;
	ALLEGRO_BITMAP *paddle = NULL;
	ALLEGRO_BITMAP *paddle2 = NULL;
	ALLEGRO_BITMAP *paddle3 = NULL;
	ALLEGRO_BITMAP *paddle4 = NULL;


	cout << "flag" << endl;



	//Game variables.
	float ball_x = 90;
	float ball_y = 70;
	float paddle_x = 10;
	float paddle_y = 50;
	float paddle2_x = 960;
	float paddle2_y = 50;
	float paddle3_x = 550;
	float paddle3_y = 50;
	float paddle4_x = 550;
	float paddle4_y = 630;

	int paddle_w = 30;
	int paddle_h = 130;
	int paddle2_h = 130;
	int paddle2_w = 30;
	int paddle3_w = 130;
	int paddle3_h = 30;
	int paddle4_w = 130;
	int paddle4_h = 30;
	int ball_w = 32;
	int ball_h = 32;

	int score = 0;
	int score2 = 0;
	cout << "flag3" << endl;

	float ball_dx = -8.0, ball_dy = 8.0;

	bool key[2] = { false, false };
	bool key2[2] = { false, false };
	bool key3[2] = { false,false };
	bool key4[2] = { false,false };

	bool redraw = true;

	bool doexit = false;

	al_init();

	al_init_font_addon();

	al_init_ttf_addon();
	cout << "flag4" << endl;

	al_init_acodec_addon();



	cout << "flag2" << endl;


	al_install_keyboard();


	timer = al_create_timer(.02);

	display = al_create_display(SCREEN_W, SCREEN_H);

	ALLEGRO_FONT *font = al_load_ttf_font("Bloodthirsty.ttf", 72, 0);



	ball = al_create_bitmap(32, 32);
	paddle = al_create_bitmap(30, 130);

	paddle2 = al_create_bitmap(30, 130);

	paddle3 = al_create_bitmap(130, 30);

	paddle4 = al_create_bitmap(130, 30);

	//use this to *draw* your own bitmaps (instead of loading them from a file)
	//before we used al_load_bitmap()
	al_set_target_bitmap(ball);


	al_clear_to_color(al_map_rgb(255, 100, 100));

	al_set_target_bitmap(paddle);

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(paddle2);

	al_clear_to_color(al_map_rgb(0, 155, 255));

	al_set_target_bitmap(paddle3);

	al_clear_to_color(al_map_rgb(100, 155, 255));

	al_set_target_bitmap(paddle4);

	al_clear_to_color(al_map_rgb(100, 55, 5));


	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));


	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();


	al_start_timer(timer);


	al_set_target_bitmap(paddle);


	al_clear_to_color(al_map_rgb(255, 100, 100));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));


	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();


	al_start_timer(timer);

	while (1)
	{
		ALLEGRO_EVENT ev;

		al_wait_for_event(event_queue, &ev);

		//////////////////////////////////////////////////////////////////////////////////
		//this section handles the bouncing-off-the-edges action


		if (ev.type == ALLEGRO_EVENT_TIMER) {////////timer section/////////////////
											 //if the box hits the left wall OR the right wall
			if (ball_x < 0 || ball_x > SCREEN_W - 32) {
				//flip the x direction
				ball_dx = -ball_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (ball_y < 0 || ball_y > SCREEN_H - 32) {
				//flip the y direction
				ball_dy = -ball_dy;
			}

			//really important code!
			//move the box in a diagonal

			ball_x += ball_dx;
			//ai.

			ball_y += ball_dy;

		}

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//if the box hits the left wall OR the right wall


			if (key[0] && paddle_y >= 0) {
				paddle_y -= 6.0;
			}

			//if the down button is pressed AND we're still above the bottom wall
			//move the box "down" by 4 pixels
			if (key[1] && paddle_y <= SCREEN_H - 124) {
				paddle_y += 6.0;
			}

			if (key2[0] && paddle2_y >= 0) {
				paddle2_y -= 6.0;
			}

			//if the down button is pressed AND we're still above the bottom wall
			//move the box "down" by 4 pixels
			if (key2[1] && paddle2_y <= SCREEN_H - 124) {
				paddle2_y += 6.0;
			}


			if (key3[0] && paddle3_y >= 0) {
				paddle3_x -= 6.0;
			}

			//if the down button is pressed AND we're still above the bottom wall
			//move the box "down" by 4 pixels
			if (key3[1] && paddle3_y <= SCREEN_H - 124) {
				paddle3_x += 6.0;
			}

			if (key4[0] && paddle4_y >= 0) {
				paddle4_x -= 6.0;
			}

			//if the down button is pressed AND we're still above the bottom wall
			//move the box "down" by 4 pixels
			if (key4[1] && paddle4_y <= SCREEN_H - 124) {
				paddle4_x += 6.0;
			}




			redraw = true;
		}

		//////////////////////////////////////////////////////////////////

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {


			switch (ev.keyboard.keycode) {


			case ALLEGRO_KEY_UP:
				key[0] = true;
				break;


			case ALLEGRO_KEY_DOWN:
				key[1] = true;
				break;

			case ALLEGRO_KEY_W:
				key2[0] = true;
				break;

			case ALLEGRO_KEY_S:
				key2[1] = true;
				break;

			case ALLEGRO_KEY_N:
				key3[0] = true;
				break;

			case ALLEGRO_KEY_M:
				key3[1] = true;
				break;

			case ALLEGRO_KEY_7:
				key4[0] = true;
				break;

			case ALLEGRO_KEY_8:
				key4[1] = true;
				break;

			}
		}
		//has something been released on the keyboard?
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[0] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[1] = false;
				break;

			case ALLEGRO_KEY_W:
				key2[0] = false;
				break;

			case ALLEGRO_KEY_S:
				key2[1] = false;
				break;

			case ALLEGRO_KEY_N:
				key3[0] = false;
				break;

			case ALLEGRO_KEY_M:
				key3[1] = false;
				break;

			case ALLEGRO_KEY_O:
				key4[0] = false;
				break;

			case ALLEGRO_KEY_P:
				key4[1] = false;
				break;



			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		//if you were supposed to redraw but there wasn't an event, don't redraw
		//render section.///////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));


			al_draw_bitmap(ball, ball_x, ball_y, 0);
			al_draw_bitmap(paddle, paddle_x, paddle_y, 0);
			al_draw_bitmap(paddle2, paddle2_x, paddle2_y, 0);
			al_draw_bitmap(paddle3, paddle3_x, paddle3_y, 0);
			al_draw_bitmap(paddle4, paddle4_x, paddle4_y, 0);

			//Collision function called. If true then reflect off the paddle.
			if (collision(ball_x, ball_y, paddle_x, paddle_y, paddle_w, paddle_h, ball_w, ball_h, paddle2_x, paddle2_y, paddle2_h, paddle2_w)) {

				cout << "boing!    ";
				ball_dx = -ball_dx;

			}
			if (collision(ball_x, ball_y, paddle2_x, paddle2_y, paddle2_w, paddle2_h, ball_w, ball_h, paddle2_x, paddle2_y, paddle2_h, paddle2_w)) {

				cout << "boing!    ";
				ball_dx = -ball_dx;
			}

			if (collision(ball_x, ball_y, paddle3_x, paddle3_y, paddle3_w, paddle3_h, ball_w, ball_h, paddle2_x, paddle2_y, paddle2_h, paddle2_w)) {

				cout << "boing!    ";
				ball_dy = -ball_dy;
			}

			if (collision(ball_x, ball_y, paddle4_x, paddle4_y, paddle4_w, paddle4_h, ball_w, ball_h, paddle2_x, paddle2_y, paddle2_h, paddle2_w)) {

				cout << "boing!    ";
				ball_dy = -ball_dy;
			}

			if (ball_x < 0) {
				score = score++;
				cout << score << endl;


			}
			if (ball_x > SCREEN_W - 32) {
				score2 = score2++;
				cout << score2 << endl;
			}




			al_draw_textf(font, al_map_rgb(255, 255, 0), 350, 50, ALLEGRO_ALIGN_CENTER, "%d", score);
			al_draw_textf(font, al_map_rgb(255, 255, 0), 650, 50, ALLEGRO_ALIGN_CENTER, "%d", score2);

			al_flip_display();
		}
	}//end game loop


	al_destroy_bitmap(ball);

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

//collision function definition.
int collision(int ball_x, int ball_y, int paddle_x, int paddle_y, int paddle_w, int paddle_h, int ball_w, int ball_h, int paddle2_y, int paddle2_x, int paddle2_w, int paddle2_h) {
	if ((ball_x > paddle_x + paddle_w) || //ball is to the right
		(ball_y > paddle_y + paddle_h) || //ball is underneath
		(ball_x + ball_w <paddle_x) || //ball is to the left
		(ball_y + ball_h <paddle_y)) { //ball is above
		return 0; //no coliision!
	}
	else
		return 1; //collision
}
