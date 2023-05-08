#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

/**
 * display_error - Displays an error message to the standard error.
 * @error_code: The error code.
 * @name_from: The name of the source file.
 * @name_to: The name of the destination file.
 * @fd_from: The file descriptor of the source file.
 *
 * Return: void
 */
void display_error(int error_code, const char *name_from, const char *name_to, int fd_from)
{
	switch (error_code)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			break;
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", name_from);
			break;
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", name_to);
			break;
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
			break;
		default:
			break;
	}
	exit(error_code);
}

/**
 * copy_file - Copies the content of one file to another.
 * @name_from: The name of the source file.
 * @name_to: The name of the destination file.
 *
 * Return: void
 */
void copy_file(const char *name_from, const char *name_to)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUF_SIZE];

	fd_from = open(name_from, O_RDONLY);
	if (fd_from == -1)
		display_error(98, name_from, name_to, fd_from);

	fd_to = open(name_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		display_error(99, name_from, name_to, fd_from);
	}

	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close(fd_from);
			close(fd_to);
			display_error(99, name_from, name_to, fd_from);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		display_error(98, name_from, name_to, fd_from);
	}

	if (close(fd_from) == -1)
		display_error(100, name_from, name_to, fd_from);

	if (close(fd_to) == -1)
		display_error(100, name_from, name_to, fd_from);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: 0 on success, or the corresponding error code.
 */
int main(int argc, char *argv[])
{
	char *name_from, *name_to;

	if (argc != 3)
	{
		display_error(97, NULL, NULL, 0);
	}

	name_from = argv[1];
	name_to = argv[2];

	copy_file(name_from, name_to);

	return (0);
}
