#pragma once
#include "../Snake_Lib/snake.h"
typedef struct {
	snake_t snake;
	size_t snake_size;
	uint8_t food[2];
	direction_t current_direction;
	int snake_file_num;
	int score;
	int snakeSpeed;
	int printSpeed;
}Snake_info;
void snakeGameCreation(Snake_info* snakeInfo);
bool playAgain();