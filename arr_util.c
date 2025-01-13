#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "parser.h"

int array_length(struct parser *ps)
{
	return ps->argc;
}

int array_loc(char *name, struct parser *ps)
{
	int i;
	bool find = false;
	int size = array_length(ps);

	for (i = 0; i < size; i++) {
		if (strcmp(name, ps->argv[i]) == 0) {
			find = true;
			break;
		}
	}

	if (!find)
		return -1;

	return i;
}
