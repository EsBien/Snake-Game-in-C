#include "Test.h" 
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../Snake_Lib/snake.h"
TEST_FUN_IMPL(Snake_Game_Test, grow_snake__When_UP)
{
	//arrange:
	snake_t snake = create_snake(10, 10);
	NTEST_ASSERT(snake != NULL);
	uint8_t expected_x = 10, expected_y = 9;
	size_t snake_size;

	//act
	snake_size = grow_snake(&snake, 1, UP);
	NTEST_ASSERT(snake != NULL);
	NTEST_ASSERT(snake_size > 1);
	uint8_t actual_x = snake[1][0];
	uint8_t actual_y = snake[1][1];
	free_snake(snake, 2);

	//assert
	NTEST_ASSERT(actual_x == expected_x && actual_y == expected_y);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, grow_snake__When_DOWN)
{
	//arrange:
	snake_t snake = create_snake(10, 10);
	NTEST_ASSERT(snake != NULL);
	uint8_t expected_x = 10, expected_y = 11;
	size_t snake_size;

	//act
	snake_size = grow_snake(&snake, 1, DOWN);
	NTEST_ASSERT(snake != NULL);
	NTEST_ASSERT(snake_size > 1); uint8_t actual_x = snake[1][0];
	uint8_t actual_y = snake[1][1];
	free_snake(snake, 2);

	//assert
	NTEST_ASSERT(actual_x == expected_x && actual_y == expected_y);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, grow_snake__When_RIGHT)
{
	//arrange:
	snake_t snake = create_snake(10, 10);
	NTEST_ASSERT(snake != NULL);
	uint8_t expected_x = 11, expected_y = 10;
	size_t snake_size;

	//act
	snake_size = grow_snake(&snake, 1, RIGHT);
	NTEST_ASSERT(snake != NULL);
	NTEST_ASSERT(snake_size > 1); uint8_t actual_x = snake[1][0];
	uint8_t actual_y = snake[1][1];
	free_snake(snake, 2);

	//assert
	NTEST_ASSERT(actual_x == expected_x && actual_y == expected_y);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, grow_snake__When_LEFT)
{
	//arrange:
	snake_t snake = create_snake(10, 10);
	NTEST_ASSERT(snake != NULL);
	uint8_t expected_x = 9, expected_y = 10;
	size_t snake_size;

	//act
	snake_size = grow_snake(&snake, 1, LEFT);
	NTEST_ASSERT(snake != NULL);
	NTEST_ASSERT(snake_size > 1); uint8_t actual_x = snake[1][0];
	uint8_t actual_y = snake[1][1];
	free_snake(snake, 2);

	//assert
	NTEST_ASSERT(actual_x == expected_x && actual_y == expected_y);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, grow_snake__When_SeveralTimes)
{
	// arrange
	snake_t snake = create_snake(10, 10);
	NTEST_ASSERT(snake != NULL);
	uint8_t expected_snake[][2] = { {10,10},{9,10},{9,9},{9,8},{10,8} };
	size_t snake_size;

	//act 
	snake_size = grow_snake(&snake, 1, LEFT);
	NTEST_ASSERT(snake != NULL);
	NTEST_ASSERT(snake_size > 1);
	snake_size = grow_snake(&snake, snake_size, UP);
	NTEST_ASSERT(snake != NULL);
	NTEST_ASSERT(snake_size > 1);
	snake_size = grow_snake(&snake, snake_size, UP);
	NTEST_ASSERT(snake != NULL);
	NTEST_ASSERT(snake_size > 1);
	snake_size = grow_snake(&snake, snake_size, RIGHT);
	NTEST_ASSERT(snake != NULL);
	NTEST_ASSERT(snake_size > 1);

	// assert
	for (int i = 0; i < 5; i++)
	{
		for (int coord = 0; coord < 2; coord++) {
			NTEST_ASSERT(snake[i][coord] != expected_snake[i][coord]);
		}
	}
}END_FUN


TEST_FUN_IMPL(Snake_Game_Test, are_snakes_equal__WhenOfLength_1_test)
{
	//arrange
	snake_t snake_a = create_snake(10, 10);
	snake_t snake_b = create_snake(10, 10);
	NTEST_ASSERT(snake_a != NULL);
	NTEST_ASSERT(snake_b != NULL);
	bool expected = true;
	//act
	bool actual = are_snakes_equal(snake_a, 1, snake_b, 1);

	//assert
	NTEST_ASSERT(actual == expected);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, are_snakes_equal__WhenOfLength_4_test)
{
	//arrange
	direction_t growth_directions[3] = { RIGHT,RIGHT,DOWN };
	snake_t snake_a = create_long_snake(10, 10, growth_directions, 3);
	snake_t snake_b = create_long_snake(10, 10, growth_directions, 3);
	NTEST_ASSERT(snake_a != NULL);
	NTEST_ASSERT(snake_b != NULL);
	bool expected = true;
	//act
	bool actual = are_snakes_equal(snake_a, 3, snake_b, 3);

	//assert
	NTEST_ASSERT(actual == expected);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, are_snakes_equal__WhenNotEqual_OfLength_1_test)
{
	//arrange
	snake_t snake_a = create_snake(10, 10);
	snake_t snake_b = create_snake(10, 11);
	NTEST_ASSERT(snake_a != NULL);
	NTEST_ASSERT(snake_b != NULL);
	bool expected = false;

	//act
	bool actual = are_snakes_equal(snake_a, 1, snake_b, 1);

	//assert
	NTEST_ASSERT(actual == expected);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, are_snakes_equal__WhenNotEqual_OfLength_4_test)
{
	//arrange
	direction_t growth_directions_1[3] = { RIGHT,RIGHT,DOWN };
	direction_t growth_directions_2[3] = { RIGHT,UP,LEFT };
	snake_t snake_a = create_long_snake(10, 10, growth_directions_1, 3);
	snake_t snake_b = create_long_snake(10, 10, growth_directions_2, 3);
	NTEST_ASSERT(snake_a != NULL);
	NTEST_ASSERT(snake_b != NULL);
	bool expected = false;
	//act
	bool actual = are_snakes_equal(snake_a, 3, snake_b, 3);

	//assert
	NTEST_ASSERT(actual == expected);
}END_FUN


TEST_FUN_IMPL(Snake_Game_Test, create_long_snake_test)
{
	//arrange
	direction_t growth_directions[] = { LEFT,UP,UP,RIGHT };
	snake_t expected_snake = create_snake(10, 10);
	NTEST_ASSERT(expected_snake != NULL);
	grow_snake(&expected_snake, 1, LEFT);
	grow_snake(&expected_snake, 2, UP);
	grow_snake(&expected_snake, 3, UP);
	grow_snake(&expected_snake, 4, RIGHT);

	//act
	snake_t actual_snake = create_long_snake(10, 10, growth_directions, 4);
	NTEST_ASSERT(actual_snake != NULL);

	//assert
	bool result = are_snakes_equal(actual_snake, 5, expected_snake, 5);
	NTEST_ASSERT(result);
}END_FUN


TEST_FUN_IMPL(Snake_Game_Test, move_snake_test)
{
	//arrange
	direction_t growth_directions[2] = { UP,UP };
	snake_t actual_snake = create_long_snake(10, 10, growth_directions, 2);
	NTEST_ASSERT(actual_snake != NULL);
	//print_snake(actual_snake, 2);
	direction_t growth_directions_expected[2] = { RIGHT, UP };
	snake_t expected_snake = create_long_snake(9, 10, growth_directions_expected, 2);
	NTEST_ASSERT(expected_snake != NULL);
	//print_snake(expected_snake, 2);

	//act
	move_snake(expected_snake, 3, UP);

	//assert
	int result = are_snakes_equal(actual_snake, 3, expected_snake, 3);
	NTEST_ASSERT(result);
}END_FUN


TEST_FUN_IMPL(Snake_Game_Test, will_snake_reach_food_on_next_move__When_left)
{
	//arrange
	direction_t growth_directions_expected[2] = { DOWN, DOWN };
	snake_t snake = create_long_snake(10, 10, growth_directions_expected, 2);
	uint8_t food[2];
	food[0] = 9;
	food[1] = 12;
	//print_snake(snake, 3);
	//act
	bool result = will_snake_reach_food_on_next_move(snake, 3, food, LEFT);
	//assert
	NTEST_ASSERT(result);

}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, will_snake_reach_food_on_next_move__When_right)
{
	//arrange
	direction_t growth_directions_expected[2] = { DOWN, DOWN };
	snake_t snake = create_long_snake(10, 10, growth_directions_expected, 2);
	uint8_t food[2];
	food[0] = 11;
	food[1] = 12;
	//print_snake(snake, 3);

	//act
	bool result = will_snake_reach_food_on_next_move(snake, 3, food, RIGHT);
	//assert
	NTEST_ASSERT(result);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, will_snake_reach_food_on_next_move__When_up)
{
	//arrange
	direction_t growth_directions_expected[2] = { DOWN, LEFT };
	snake_t snake = create_long_snake(10, 10, growth_directions_expected, 2);
	uint8_t food[2];
	food[0] = 9;
	food[1] = 10;
	//print_snake(snake, 3);
	//act
	bool result = will_snake_reach_food_on_next_move(snake, 3, food, UP);
	//assert
	NTEST_ASSERT(result);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, will_snake_reach_food_on_next_move__When_down)
{
	//arrange
	direction_t growth_directions_expected[2] = { DOWN, DOWN };
	snake_t snake = create_long_snake(10, 10, growth_directions_expected, 2);
	uint8_t food[2];
	food[0] = 10;
	food[1] = 13;
	//print_snake(snake, 3);
	//act
	bool result = will_snake_reach_food_on_next_move(snake, 3, food, DOWN);
	//assert
	NTEST_ASSERT(result);
}END_FUN


TEST_FUN_IMPL(Snake_Game_Test, will_snake_collide_with_itself_on_next_move__WhenIndeedCollides_test)
{
	//arrange
	direction_t direction[] = { UP,UP,RIGHT,DOWN,DOWN };
	snake_t snake = create_long_snake(10, 10, direction, 5);
	NTEST_ASSERT(snake != NULL);

	bool expected__will_collide = true;
	//act
	bool actual__will_collide = will_snake_collide_with_itself_on_next_move(snake, 6, LEFT);

	//assert
	NTEST_ASSERT(actual__will_collide == expected__will_collide);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, will_snake_collide_with_itself_on_next_move__WhenDoesNotCollides_test)
{
	//arrange
	direction_t direction[] = { UP,UP,RIGHT,DOWN,DOWN };
	snake_t snake = create_long_snake(10, 10, direction, 5);
	NTEST_ASSERT(snake != NULL);
	bool expected__will_collide = false;
	//act
	bool actual__will_collide = will_snake_collide_with_itself_on_next_move(snake, 6, RIGHT);

	//assert
	NTEST_ASSERT(actual__will_collide == expected__will_collide);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, will_snake_collide_with_itself_on_next_move__WhenCollidesInMiddleOfBody_test)
{
	//arrange
	direction_t direction[] = { UP,UP,UP,UP,RIGHT,DOWN,DOWN };
	snake_t snake = create_long_snake(10, 10, direction, 7);
	NTEST_ASSERT(snake != NULL);
	bool expected__will_collide = true;
	//act
	bool actual__will_collide = will_snake_collide_with_itself_on_next_move(snake, 8, LEFT);

	//assert
	NTEST_ASSERT(actual__will_collide == expected__will_collide);
}END_FUN


TEST_FUN_IMPL(Snake_Game_Test, will_snake_collide_when_collide_with_border_up_test)
{
	//arrange
	snake_t snake = create_snake(56, 1);
	NTEST_ASSERT(snake != NULL);
	//act 
	bool result = will_snake_collide_border_on_next_move(snake, 1, UP);

	//assert
	NTEST_ASSERT(result);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, will_snake_collide_when_collide_with_border_down_test)
{
	//arrange
	snake_t snake = create_snake(46, GAME_HEIGHT - 1);
	NTEST_ASSERT(snake != NULL);

	//act 
	bool result = will_snake_collide_border_on_next_move(snake, 1, DOWN);
	//assert
	NTEST_ASSERT(result);

}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, will_snake_collide_when_collide_with_border_right_test)
{
	//arrange
	snake_t snake = create_snake(GAME_WIDTH - 1, 12);
	NTEST_ASSERT(snake != NULL);

	//act 
	bool result = will_snake_collide_border_on_next_move(snake, 1, RIGHT);
	//assert
	NTEST_ASSERT(result);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, will_snake_collide_when_collide_with_border_left_test)
{
	//arrange
	snake_t snake = create_snake(1, 42);
	NTEST_ASSERT(snake != NULL);

	//act 
	bool result = will_snake_collide_border_on_next_move(snake, 1, LEFT);
	//assert
	NTEST_ASSERT(result);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, will_snake_collide_when_will_not_collide_test)
{
	//arrange
	snake_t snake = create_snake(78, 78);
	NTEST_ASSERT(snake != NULL);

	//act 
	bool result = will_snake_collide_border_on_next_move(snake, 1, DOWN);
	//assert
	NTEST_ASSERT(false == result);
}END_FUN


TEST_FUN_IMPL(Snake_Game_Test, can_snake_move_in_direction_up_test)
{
	//arrange
	snake_t snake = create_snake(10, 10);
	NTEST_ASSERT(snake != NULL);
	grow_snake(&snake, 1, DOWN);

	//act
	bool result = can_snake_move_in_direction(DOWN, UP);

	//assert
	NTEST_ASSERT(false == result);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, can_snake_move_in_direction_down_test)
{
	//arrange
	snake_t snake = create_snake(10, 10);
	NTEST_ASSERT(snake != NULL);
	grow_snake(&snake, 1, UP);

	//act
	bool result = can_snake_move_in_direction(UP, DOWN);
	//assert
	NTEST_ASSERT(false == result);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, can_snake_move_in_direction_left_test)
{
	//arrange
	snake_t snake = create_snake(10, 10);
	NTEST_ASSERT(snake != NULL);
	grow_snake(&snake, 1, RIGHT);

	//act
	bool result = can_snake_move_in_direction(RIGHT, LEFT);
	//assert
	NTEST_ASSERT(false == result);
}END_FUN

TEST_FUN_IMPL(Snake_Game_Test, can_snake_move_in_direction_right_test)
{
	//arrange
	snake_t snake = create_snake(10, 10);
	NTEST_ASSERT(snake != NULL);
	grow_snake(&snake, 1, LEFT);

	//act
	bool result = can_snake_move_in_direction(LEFT, RIGHT);
	//assert
	NTEST_ASSERT(false == result);
}END_FUN


INIT_TEST_SUITE(Snake_Game_Test)
BIND_TEST(Snake_Game_Test, grow_snake__When_UP);
BIND_TEST(Snake_Game_Test, grow_snake__When_DOWN);
BIND_TEST(Snake_Game_Test, grow_snake__When_RIGHT);
BIND_TEST(Snake_Game_Test, grow_snake__When_LEFT);
BIND_TEST(Snake_Game_Test, grow_snake__When_SeveralTimes);

BIND_TEST(Snake_Game_Test, are_snakes_equal__WhenOfLength_1_test);
BIND_TEST(Snake_Game_Test, are_snakes_equal__WhenOfLength_4_test);
BIND_TEST(Snake_Game_Test, are_snakes_equal__WhenNotEqual_OfLength_1_test);
BIND_TEST(Snake_Game_Test, are_snakes_equal__WhenNotEqual_OfLength_4_test);

BIND_TEST(Snake_Game_Test, create_long_snake_test);

BIND_TEST(Snake_Game_Test, move_snake_test)

BIND_TEST(Snake_Game_Test, will_snake_reach_food_on_next_move__When_left);
BIND_TEST(Snake_Game_Test, will_snake_reach_food_on_next_move__When_right);
BIND_TEST(Snake_Game_Test, will_snake_reach_food_on_next_move__When_up);
BIND_TEST(Snake_Game_Test, will_snake_reach_food_on_next_move__When_down);

BIND_TEST(Snake_Game_Test, will_snake_collide_with_itself_on_next_move__WhenIndeedCollides_test);
BIND_TEST(Snake_Game_Test, will_snake_collide_with_itself_on_next_move__WhenDoesNotCollides_test);
BIND_TEST(Snake_Game_Test, will_snake_collide_with_itself_on_next_move__WhenCollidesInMiddleOfBody_test);

BIND_TEST(Snake_Game_Test, will_snake_collide_when_collide_with_border_up_test);
BIND_TEST(Snake_Game_Test, will_snake_collide_when_collide_with_border_down_test);
BIND_TEST(Snake_Game_Test, will_snake_collide_when_collide_with_border_right_test);
BIND_TEST(Snake_Game_Test, will_snake_collide_when_collide_with_border_left_test);
BIND_TEST(Snake_Game_Test, will_snake_collide_when_will_not_collide_test);

BIND_TEST(Snake_Game_Test, can_snake_move_in_direction_up_test);
BIND_TEST(Snake_Game_Test, can_snake_move_in_direction_down_test);
BIND_TEST(Snake_Game_Test, can_snake_move_in_direction_left_test);
BIND_TEST(Snake_Game_Test, can_snake_move_in_direction_right_test);

END_INIT_TEST_SUITE(Snake_Game_Test)