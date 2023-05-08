#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * display_error - Display error message to stderr and exit
 * @msg: The error message to display
 *
 * Description: Prints the error message to stderr and exits with status code 98.
 */
void display_error(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * read_elf_header - Read the ELF header from the file
 * @filename: The name of the ELF file
 * @header: Pointer to the ELF header structure to fill
 *
 * Description: Opens the ELF file, reads the ELF header, and fills the provided structure.
 */
void read_elf_header(char *filename, Elf64_Ehdr *header)
{
	int fd, read_size;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		display_error("Error: Cannot open file");

	read_size = read(fd, header, sizeof(Elf64_Ehdr));
	if (read_size == -1)
		display_error("Error: Cannot read from file");

	if (read_size != sizeof(Elf64_Ehdr))
		display_error("Error: Invalid ELF file");

	close(fd);
}

/**
 * print_elf_header_info - Print the information from the ELF header
 * @header: Pointer to the ELF header structure
 *
 * Description: Prints the information contained in the ELF header structure.
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("Invalid class\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}

	/* Print other fields of the ELF header as required */
}

/**
 * main - Entry point of the program
 * @argc: The argument count
 * @argv: The argument vector
 * Return: 0 on success, 98 on failure
 *
 * Description: Reads the ELF header from the specified ELF file and prints the information.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	read_elf_header(argv[1], &header);
	print_elf_header_info(&header);

	return (0);
}
