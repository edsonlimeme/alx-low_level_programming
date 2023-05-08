#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * display_error - Displays error messages to the standard error
 * @error_code: The error code
 * @name_from: The name of the source file
 * @name_to: The name of the destination file
 * @fd_from: The file descriptor of the source file
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
}

/**
 * copy_file - Copies the content of one file to another
 * @file_from: The name of the source file
 * @file_to: The name of the destination file
 * Return: 1 on success, -1 on failure
 */
int copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (file_from == NULL)
		return (-1);

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		display_error(98, file_from, file_to, 0);
		return (-1);
	}

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		display_error(99, file_from, file_to, fd_from);
		close(fd_from);
		return (-1);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			display_error(99, file_from, file_to, fd_from);
			close(fd_from);
			close(fd_to);
			return (-1);
		}
	}

	if (bytes_read == -1)
	{
		display_error(98, file_from, file_to, fd_from);
		close(fd_from);
		close(fd_to);
		return (-1);
	}

	if (close(fd_from) == -1)
	{
		display_error(100, file_from, file_to, fd_from);
		close(fd_to);
		return (-1);
	}

	if (close(fd_to) == -1)
	{
		display_error(100, file_from, file_to, fd_from);
		return (-1);
	}

	return (1);
}

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array of command line argument strings
 * Return: 0 on success, or the corresponding error code on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		display_error(97, NULL, NULL, 0);
		return (97);
	}

	if (copy_file(argv[1],
