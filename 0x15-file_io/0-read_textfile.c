#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: Pointer to the name of the file to read
 * @letters: The number of letters to read and print
 *
 * Return: The number of letters it could read and print, or 0 if an error occurs
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t txtread, txtwritten;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	txtread = read(fd, buffer, letters);
	if (txtread == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	buffer[txtread] = '\0';
	txtwritten = write(STDOUT_FILENO, buffer, txtread);
	if (txtwritten == -1 || txtwritten != txtread)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);

	return (txtwritten);
}
