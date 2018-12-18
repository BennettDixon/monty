#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - the entry point for Monty Interp
 *
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	int script_fd = -1;

	if (argc != 2)
		return (usage_error());
	script_fd = open(argv[1], O_RDONLY);
	if (script_fd == -1)
		return (f_open_error(argv[1]));
	return (run_monty(script_fd));
}
