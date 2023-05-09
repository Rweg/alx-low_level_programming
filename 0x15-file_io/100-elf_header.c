#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <elf.h>

#define BUF_SIZE 128

/**
 * elf_header - A program that displays the information contained in the ELF header
 *              at the start of an ELF file.
 *
 * @argc: The number of arguments passed to the program.
 * @argv: A pointer to an array of strings of the arguments passed to the program.
 *
 * Return: On success, returns 0. On failure, exits with status code 98 and 
 * 		displays an error message to stderr.
 */

void print_error(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

int main(int argc, char **argv)
{
	int fd;
	Elf32_Ehdr eh;
	int i;

	if (argc != 2)
	{
		print_error("Invalid number of arguments");
	}
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		print_error("Unable to open file");
	}

	if (read(fd, &eh, sizeof(eh)) != sizeof(eh))
	{
		print_error("Unable to read ELF header");
	}

	if (memcmp(eh.e_ident, ELFMAG, SELFMAG) != 0)
	{
		print_error("Not an ELF file");
	}
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", eh.e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             %u\n", eh.e_ident[EI_CLASS]);
	printf("  Data:                              %u\n", eh.e_ident[EI_DATA]);
	printf("  Version:                           %u\n", eh.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %u\n", eh.e_ident[EI_OSABI]);
	printf("  ABI Version:");
	printf("			%u\n", eh.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %u\n", eh.e_type);
	printf("  Entry point address:               %u\n", eh.e_entry);
	printf("  %s\n", eh.e_ident[EI_DATA] == ELFDATA2LSB
			? "  (little endian)"
			: "  (big endian)");
	close(fd);
	return (0);
}
