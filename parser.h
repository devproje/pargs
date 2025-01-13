#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdbool.h>

struct parser {
	int argc;
	char **argv;
};

struct parser new_parser(int argc, char **argv);

int export_int_arg(const char *name, struct parser *ps);
bool export_bool_arg(const char *name, struct parser *ps);
char *export_string_arg(const char *name, struct parser *ps);

#endif
