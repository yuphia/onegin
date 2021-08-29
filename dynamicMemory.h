#pragma once

#define BUFFER_COLUMNSIZE_SIZE 20000
#define BUFFER_ROW_SIZE 10000

#include <stdlib.h>

static char buffer [BUFFER_COLUMN_SIZE][BUFFER_ROW_SIZE];
static int *pointer = &buffer[0][0];

