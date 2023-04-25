#include <stdbool.h>
#include <stdio.h>
#include "Test.h"


IMPORT_TESTS(Snake_Game_Test);


int main() {

	init_global_memory(sizeof(int) * 10, HEAP_BASED_MEMORY);

	RUN_TESTS(Snake_Game_Test);

	return 0;

}
