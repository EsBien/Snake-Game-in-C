// Snake_Runner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h> 
#include <windows.h>  
#include <conio.h>
#include <stdbool.h>
#include <stdint.h>
#include "../Snake_Lib/snake.h"

int main()
{
	
	snake_t snake = create_snake(5, 5);		
	size_t snake_size = 1;
	uint8_t food[] = { 4,5 };				
	direction_t current_direction = RIGHT;
	bool is_game_time = true;
	draw_borders();
	int snake_file_num = 0;
	int score = 0;
	int snakeSpeed = 300;
	int printSpeed = 10;
	gotoxy(GAME_WIDTH + 5, 7);
	printf("Snake Speed: %d", printSpeed);
	gotoxy(GAME_WIDTH + 5, 5);
	printf("Speed up press on '+' Speed down press on '-'");
	gotoxy(GAME_WIDTH + 5, 3);
	printf("Score: %d", score);
	while (is_game_time)
	{
		draw_snake(snake, snake_size);
		draw_food(food);
		Sleep(snakeSpeed);
		erase_snake_tail(snake, snake_size);
		if (_kbhit())
		{
			int key = _getch();
			int requested_direction = INVALID_DIRECTION;
			switch (key)
			{
			case 'w': requested_direction = UP; break;
			case 's': requested_direction = DOWN; break;
			case 'a': requested_direction = LEFT; break;
			case 'd': requested_direction = RIGHT; break;
			case 61: 
			{
				snakeSpeed -= 20;
				gotoxy(GAME_WIDTH + 5, 7);
				printf("Snake Speed: %d", ++printSpeed);
				break;
			}
				snakeSpeed += 20; break;
			case 45: 
			{
				snakeSpeed += 20; 
				gotoxy(GAME_WIDTH + 5, 7);
				printf("Snake Speed: %d", --printSpeed);
				break;
			}
			case 'q': is_game_time = false; break;
			}
			if (requested_direction != INVALID_DIRECTION)
			{
				if (can_snake_move_in_direction(current_direction, requested_direction))
					current_direction = requested_direction;
			}
		}
		if (will_snake_collide_border_on_next_move(snake, snake_size, current_direction))
		{
			is_game_time = false;
			printf("Game Over!! snake bumped into border, Your score is %d", score);
			continue;
		}
		if (will_snake_collide_with_itself_on_next_move(snake, snake_size, current_direction))
		{
			is_game_time = false;
			printf("Game Over!! snake bumped into itself, Your score is %d", score);
			continue;
		}
		bool should_grow = will_snake_reach_food_on_next_move(snake, snake_size, food, current_direction);
		if (should_grow)
		{
			snake_size = grow_snake(&snake, snake_size, current_direction);
			set_new_food_location(snake, snake_size, food);
			score += 10;
			gotoxy(GAME_WIDTH + 5,3);
			printf("Score: %d", score);
		}
		else
		{
			move_snake(snake, snake_size, current_direction);
		}
	}
	free_snake(snake, snake_size);
}