#include <stdio.h>
#include <error.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "parser.h"
#include "arr_util.h"

struct parser new_parser(int argc, char **argv)
{
	struct parser ps = {
		.argc = argc,
		.argv = argv
	};

	return ps;
}

int export_int_arg(const char *name, struct parser *ps)
{
	long num;
	char *ptr;
	int converted;
    errno = 0;

	int loc = array_loc(name, ps);
	if (loc == -1)
		return 0;

	if (ps->argv[loc + 1] == NULL) {
		printf("error: %s integer argument is not defined\n", name);
		return 0;
	}

	if (ps->argv[loc + 1][0] == '-' || ps->argv[loc + 1][1] == '-') {
		printf("error: %s integer argument is not defined\n", name);
		return 0;
	}

    num = strtol(ps->argv[loc + 1], &ptr, 10);

    if (errno == ERANGE) {
        printf("error: Number out of range.\n");
		return 0;
    }
	
	if (*ptr != '\0') {
        printf("error: invalid characters found in input: '%s'\n", ptr);
		return 0;
    }

	if (num < INT_MIN && num > INT_MAX) {
		printf("error: number exceeds int range.\n");
		return 0;
    }

	converted = (int)num;
	return converted;
}

bool export_bool_arg(const char *name, struct parser *ps)
{
	int loc = array_loc(name, ps);
	if (loc == -1)
		return false;

	return true;
}

char *export_string_arg(const char *name, struct parser *ps)
{
	int loc = array_loc(name, ps);
	if (loc == -1)
		return NULL;

	if (ps->argv[loc + 1] == NULL) {
		printf("error: %s string argument is not defined\n", name);
		return NULL;
	}

	if (ps->argv[loc + 1][0] == '-' || ps->argv[loc + 1][1] == '-') {
		printf("error: %s string argument is not defined\n", name);
		return NULL;
	}

	return ps->argv[loc + 1];
}
