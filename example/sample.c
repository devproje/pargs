#include <stdio.h>

#include "../parser.h"

int main(int argc, char **argv)
{
	struct parser ps = new_parser(argc, argv);
	char *name = export_string_arg("--name", &ps);
	if (name == NULL)
		return -1;
	int age = export_int_arg("--age", &ps);
	if (age == 0)
		return -1;
	int male = export_bool_arg("--male", &ps);

	printf("name: %s\n", name);
	printf("age: %d\n", age);
	printf("male: %s\n", male == 1 ? "true" : "false");

	return 0;
}
