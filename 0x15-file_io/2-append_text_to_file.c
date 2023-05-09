#include <main.h>

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: The name of the file
 * @text_content: The string to add at the end of the file
 *
 * Return: 1 on success and -1 if the function fails
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, holder, len = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;

		holder = write(fd, text_content, len);
		if (holder == -1 || holder != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
