// Snake_Runner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h> 
#include <windows.h>  
#include <conio.h>
#include <stdbool.h>
#include <stdint.h>
#include "Snake_Runner.h"
bool playAgain()
{
	char exit = ' ';
	gotoxy(GAME_WIDTH + 4, 14);
	printf("Exit the game y/n:");
	scanf("%c", &exit);
	return exit == 'y' ? false : true;
}
void snakeGameCreation(Snake_info* snakeInfo)
{
	snakeInfo->snake = create_snake(5, 5);
	snakeInfo->snake_size = 1;
	snakeInfo->food[0] = 4;
	snakeInfo->food[1] = 5;
	snakeInfo->current_direction = RIGHT;
	draw_borders();
	snakeInfo->snake_file_num = 0;
	snakeInfo->score = 0;
	snakeInfo->snakeSpeed = 300;
	snakeInfo->printSpeed = 10;
	gotoxy(GAME_WIDTH + 5, 7);
	printf("Snake Speed: %d", snakeInfo->printSpeed);
	gotoxy(GAME_WIDTH + 5, 5);
	printf("Speed up press on '+' Speed down press on '-'");
	gotoxy(GAME_WIDTH + 5, 3);
	printf("Score: %d", snakeInfo->score);
}
void eraseGame()
{
	//erace grame over text
	gotoxy(GAME_WIDTH + 4, 12);
	printf("                                                       ");
	//erace to exit text
	gotoxy(GAME_WIDTH + 4, 14);
	printf("                       ");
	//erace score text
	gotoxy(GAME_WIDTH + 5, 3);
	printf("                       ");
	for(int i=0;i<GAME_WIDTH;i++)
		for (int j = 0; j < GAME_HEIGHT; j++)
		{
			gotoxy(i, j);
			printf("%c",ERASE);
		}
}
int main()
{
	Snake_info snakeInfo;
	snakeGameCreation(&snakeInfo);
	bool is_game_time = true;
	draw_borders();
	while (is_game_time)
	{
		draw_snake(snakeInfo.snake, snakeInfo.snake_size);
		draw_food(snakeInfo.food);
		Sleep(snakeInfo.snakeSpeed);
		erase_snake_tail(snakeInfo.snake, snakeInfo.snake_size);
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
			case 61: //'+'
			{
				snakeInfo.snakeSpeed -= 20;
				gotoxy(GAME_WIDTH + 5, 7);
				printf("Snake Speed: %d", ++snakeInfo.printSpeed);
				break;
			}
			snakeInfo.snakeSpeed += 20; break;
			case 45:  //'-'
			{
				snakeInfo.snakeSpeed += 20;
				gotoxy(GAME_WIDTH + 5, 7);
				printf("Snake Speed: %d", --snakeInfo.printSpeed);
				break;
			}
			case 'q': is_game_time = false; break;
			}
			if (requested_direction != INVALID_DIRECTION)
			{
				if (can_snake_move_in_direction(snakeInfo.current_direction, requested_direction))
					snakeInfo.current_direction = requested_direction;
			}
		}
		bool should_grow = will_snake_reach_food_on_next_move(snakeInfo.snake, snakeInfo.snake_size, snakeInfo.food, snakeInfo.current_direction);
		if (should_grow)
		{
			snakeInfo.snake_size = grow_snake(&snakeInfo.snake, snakeInfo.snake_size, snakeInfo.current_direction);
			set_new_food_location(snakeInfo.snake, snakeInfo.snake_size, snakeInfo.food);
			snakeInfo.score += 10;
			gotoxy(GAME_WIDTH + 5, 3);
			printf("Score: %d", snakeInfo.score);
		}
		else
		{
			move_snake(snakeInfo.snake, snakeInfo.snake_size, snakeInfo.current_direction);
		}
		if (will_snake_collide_border_on_next_move(snakeInfo.snake, snakeInfo.snake_size, snakeInfo.current_direction) ||
			will_snake_collide_with_itself_on_next_move(snakeInfo.snake, snakeInfo.snake_size, snakeInfo.current_direction))
		{
			gotoxy(GAME_WIDTH + 4, 12);
			printf("Game Over!! snake bumped opppss, Your score is %d", snakeInfo.score);
			is_game_time = playAgain();
			if (is_game_time)
			{
				eraseGame();
				snakeGameCreation(&snakeInfo);	
			}

			//continue;
		}

	}
	free_snake(snakeInfo.snake, snakeInfo.snake_size);
}